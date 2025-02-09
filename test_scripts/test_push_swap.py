import subprocess
import random
import numpy as np
from typing import List, Tuple
import json
from pathlib import Path
import time
from multiprocessing import Pool

class PushSwapTester:
	def __init__(self, push_swap_path: str = "./push_swap",
				 checker_path: str = "./checker_Mac",
				 max_moves: int = 700,
				 sequence_length: int = 100,
				 population_size: int = 50,
				 generations: int = 100,
				 mutation_rate: float = 0.1):
		self.push_swap_path = push_swap_path
		self.checker_path = checker_path
		self.max_moves = max_moves
		self.sequence_length = sequence_length
		self.population_size = population_size
		self.generations = generations
		self.mutation_rate = mutation_rate
		self.best_sequences = []
		self.history = []

		Path("results").mkdir(exist_ok=True)

	def run_push_swap(self, numbers: List[int]) -> Tuple[int, bool]:
		numbers_str = " ".join(map(str, numbers))

		try:
			push_swap = subprocess.Popen(
				f"{self.push_swap_path} {numbers_str}",
				shell=True,
				stdout=subprocess.PIPE,
				stderr=subprocess.PIPE
			)
			output, _ = push_swap.communicate()
			moves = output.decode().count('\n')

			checker = subprocess.Popen(
				f"{self.checker_path} {numbers_str}",
				shell=True,
				stdin=subprocess.PIPE,
				stdout=subprocess.PIPE
			)
			checker.stdin.write(output)
			checker.stdin.close()
			checker_output = checker.stdout.read().decode().strip()

			is_sorted = checker_output == "OK"
			return moves, is_sorted

		except subprocess.SubprocessError:
			return float('inf'), False

	def generate_sequence(self) -> List[int]:
		if not self.history:
			return random.sample(range(1, self.sequence_length * 2), self.sequence_length)

		high_move_sequences = sorted(self.history, key=lambda x: x['moves'], reverse=True)[:5]
		patterns = []

		for seq in high_move_sequences:
			numbers = seq['sequence']
			for i in range(len(numbers) - 3):
				if seq['moves'] > self.max_moves * 0.8:
					patterns.append(numbers[i:i+3])

		new_sequence = []
		while len(new_sequence) < self.sequence_length:
			if patterns and random.random() < 0.3:
				pattern = random.choice(patterns)
				new_sequence.extend(pattern)
			else:
				new_sequence.append(random.randint(1, self.sequence_length * 2))

		new_sequence = list(dict.fromkeys(new_sequence))
		while len(new_sequence) < self.sequence_length:
			num = random.randint(1, self.sequence_length * 2)
			if num not in new_sequence:
				new_sequence.append(num)

		return new_sequence[:self.sequence_length]

	def mutate_sequence(self, sequence: List[int]) -> List[int]:
		mutated = sequence.copy()
		mutation_type = random.random()

		if mutation_type < 0.3:
			chunk_size = random.randint(2, 10)
			pos1 = random.randint(0, len(mutated) - chunk_size)
			pos2 = random.randint(0, len(mutated) - chunk_size)
			mutated[pos1:pos1+chunk_size], mutated[pos2:pos2+chunk_size] = \
				mutated[pos2:pos2+chunk_size], mutated[pos1:pos1+chunk_size]

		elif mutation_type < 0.6:
			start = random.randint(0, len(mutated) - 2)
			end = random.randint(start + 1, len(mutated))
			mutated[start:end] = reversed(mutated[start:end])

		else:
			num_swaps = random.randint(1, 5)
			for _ in range(num_swaps):
				i, j = random.sample(range(len(mutated)), 2)
				mutated[i], mutated[j] = mutated[j], mutated[i]

		return mutated

	def run_generation(self):
		sequences = []
		with Pool() as pool:
			results = pool.map(self.run_push_swap, [self.generate_sequence() for _ in range(self.population_size)])

		for sequence, (moves, is_sorted) in zip([self.generate_sequence() for _ in range(self.population_size)], results):
			result = {
				'sequence': sequence,
				'moves': moves,
				'is_sorted': is_sorted,
				'timestamp': time.time()
			}
			sequences.append(result)
			self.history.append(result)

			if moves > self.max_moves and is_sorted:
				self.best_sequences.append(result)
				self.save_result(result)

		return sequences

	def save_result(self, result: dict):
		timestamp = time.strftime("%Y%m%d-%H%M%S")
		filename = f"results/sequence_{result['moves']}moves_{timestamp}.json"

		with open(filename, 'w') as f:
			json.dump({
				'sequence': result['sequence'],
				'moves': result['moves'],
				'is_sorted': result['is_sorted']
			}, f, indent=2)

	def run(self):
		print(f"Starting push_swap testing with {self.sequence_length} numbers...")

		for generation in range(self.generations):
			sequences = self.run_generation()
			best_sequence = min(sequences, key=lambda x: x['moves'])
			worst_sequence = max(sequences, key=lambda x: x['moves'])

			print(f"\nGeneration {generation + 1}/{self.generations}")
			print(f"Best sequence: {best_sequence['moves']} moves")
			print(f"Worst sequence: {worst_sequence['moves']} moves")
			print(f"Found {len(self.best_sequences)} sequences exceeding {self.max_moves} moves")

			if len(self.best_sequences) >= 5:
				print("\nFound multiple challenging sequences! Check the results directory.")
				break

if __name__ == "__main__":
	tester = PushSwapTester()
	tester.run()
