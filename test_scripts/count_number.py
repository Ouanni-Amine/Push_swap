def count_numbers():
	print("Enter all your numbers in a single line, separated by spaces:")
	user_input = input()

	numbers = []
	for num in user_input.split():
		try:
			num = num.strip('"\'')
			number = float(num)
			numbers.append(number)
		except ValueError:
			print(f"Warning: '{num}' is not a valid number and was skipped.")
			continue

	print(f"\nYou entered {len(numbers)} numbers.")
	if numbers:
		print("The numbers you entered are:", numbers)

if __name__ == "__main__":
	count_numbers()
