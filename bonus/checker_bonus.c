/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:22:26 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/05 20:46:56 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_moves_checker_2(t_ps **stacka, t_ps **stackb, t_psb *tmp)
{
	if (!ft_strcmp(tmp->move, "rrr"))
		rrr(stacka, stackb);
	else if (!ft_strcmp(tmp->move, "sa"))
		sa(stacka);
	else if (!ft_strcmp(tmp->move, "sb"))
		sb(stackb);
	else if (!ft_strcmp(tmp->move, "ss"))
		ss(stacka, stackb);
}

void	ft_moves_checker(t_ps **stacka, t_ps **stackb, t_psb **instructions)
{
	t_psb	*tmp;

	tmp = *instructions;
	while (tmp)
	{
		if (!ft_strcmp(tmp->move, "pa"))
			push_a(stacka, stackb);
		else if (!ft_strcmp(tmp->move, "pb"))
			push_b(stacka, stackb);
		else if (!ft_strcmp(tmp->move, "ra"))
			ra(stacka);
		else if (!ft_strcmp(tmp->move, "rb"))
			rb(stackb);
		else if (!ft_strcmp(tmp->move, "rr"))
			rr(stackb, stacka);
		else if (!ft_strcmp(tmp->move, "rra"))
			rra(stacka);
		else if (!ft_strcmp(tmp->move, "rrb"))
			rrb(stackb);
		else
			ft_moves_checker_2(stacka, stackb, tmp);
		tmp = tmp->next;
	}
}

void	ft_valide_moves(t_psb **instructions, t_ps **stacka)
{
	t_psb	*tmp;

	tmp = *instructions;
	while (tmp)
	{
		if (ft_strcmp(tmp->move, "pa") && ft_strcmp(tmp->move, "pb")
			&& ft_strcmp(tmp->move, "ra") && ft_strcmp(tmp->move, "rb")
			&& ft_strcmp(tmp->move, "rr") && ft_strcmp(tmp->move, "rra")
			&& ft_strcmp(tmp->move, "rrb") && ft_strcmp(tmp->move, "rrr")
			&& ft_strcmp(tmp->move, "sa") && ft_strcmp(tmp->move, "sb")
			&& ft_strcmp(tmp->move, "ss"))
		{
			ft_freenode(stacka);
			ft_freebonus(instructions);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		tmp = tmp->next;
	}
}

void	ft_checker_2(t_ps **stacka, t_ps **stackb, t_psb **instructions)
{
	if (!*instructions)
	{
		if (ft_issorted(*stacka))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ft_freenode(stacka);
		return ;
	}
	ft_valide_moves(instructions, stacka);
	ft_moves_checker(stacka, stackb, instructions);
	if (ft_issorted(*stacka) && *stackb == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_freenode(stacka);
	ft_freenode(stackb);
	ft_freebonus(instructions);
}

void	ft_checker(t_ps **stacka, t_ps **stackb)
{
	char	*line;
	t_psb	*instructions;
	t_psb	*newnode;
	char	*new_line;

	instructions = NULL;
	line = get_next_line(0);
	while (line)
	{
		new_line = ft_strtrim(line, "\n");
		free(line);
		if (!new_line)
			ft_clean_part2(stacka, &instructions, new_line);
		newnode = ft_lstnew_str(new_line);
		if (!newnode)
			ft_clean_part2(stacka, &instructions, new_line);
		ft_lstadd_back_str(&instructions, newnode);
		free(new_line);
		line = get_next_line(0);
	}
	ft_checker_2(stacka, stackb, &instructions);
}
