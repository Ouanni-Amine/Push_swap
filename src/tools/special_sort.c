/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:06:06 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/06 15:47:01 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_two(t_ps **stack, char c)
{
	if (!ft_issorted(*stack) && c == 'b')
		sb(stack);
	else if (!ft_issorted(*stack) && c == 'a')
		sa(stack);
}

void	ft_sort_three(t_ps **stacka)
{
	int	n1;
	int	n2;
	int	n3;

	if (ft_issorted(*stacka))
		return ;
	n1 = (*stacka)->num;
	n2 = (*stacka)->next->num;
	n3 = (*stacka)->next->next->num;
	if (n1 > n2 && n2 > n3)
	{
		ra(stacka);
		sa(stacka);
	}
	else if (n1 > n2 && n1 > n3)
		ra(stacka);
	else if (n1 < n3 && n2 < n3)
		sa(stacka);
	else if (n1 > n3)
		rra(stacka);
	else if (n1 < n2 && n1 < n3)
	{
		rra(stacka);
		sa(stacka);
	}
}

void	ft_sort_five(t_ps **stacka, t_ps **stackb)
{
	while (ft_lstsize(*stacka) > 3)
	{
		if ((*stacka)->index == 0 || (*stacka)->index == 1)
			push_b(stacka, stackb);
		else
			ra(stacka);
	}
	if (ft_issorted(*stackb))
		sb(stackb);
	if (!ft_issorted(*stacka))
		ft_sort_three(stacka);
	while (ft_lstsize(*stackb))
		push_a(stacka, stackb);
}

void	ft_sort_four(t_ps **stacka, t_ps **stackb)
{
	t_ps	*current;

	current = *stacka;
	while (current->index != 0)
	{
		current = current->next;
		ra(stacka);
	}
	push_b(stacka, stackb);
	ft_sort_three(stacka);
	push_a(stacka, stackb);
}

void	ft_sort_5nd4(t_ps **stacka, t_ps **stackb)
{
	if (ft_lstsize(*stacka) == 5)
		ft_sort_five(stacka, stackb);
	else
		ft_sort_four(stacka, stackb);
}
