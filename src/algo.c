/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:06:37 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/07 17:33:00 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_ps **stacka)
{
	int		index;
	t_ps	*current;
	t_ps	*compare;

	current = *stacka;
	while (current)
	{
		index = 0;
		compare = *stacka;
		while (compare)
		{
			if (compare->num < current->num)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	ft_patterns_check(t_ps *stacka)
{
	int		peak;
	int		down;
	int		up;
	int		direction;
	t_ps	*tmp;

	peak = 0;
	down = 0;
	up = 0;
	direction = 0;
	tmp = stacka;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			down++;
		tmp = tmp->next;
	}
	if (down > (ft_lstsize(stacka) - 1) * 0.7)
		return (1);
	return (ft_patterns_check2(stacka, peak, up, direction));
}

void	ft_semi_sort(t_ps **stacka, t_ps **stackb)
{
	int	i;
	int	range;
	int	pattern;

	i = 0;
	pattern = ft_patterns_check(*stacka);
	range = ft_range(stacka);
	while (*stacka)
	{
		if ((*stacka)->index <= i)
		{
			push_b(stacka, stackb);
			i++;
		}
		else if ((*stacka)->index <= (i + range))
		{
			push_b(stacka, stackb);
			rb(stackb);
			i++;
		}
		else
			ft_semi_sort_complete(stacka, pattern);
	}
}

void	ft_final_sort(t_ps **stacka, t_ps **stackb)
{
	int		top;
	int		down;
	int		target;
	t_ps	*current;

	down = 0;
	top = 0;
	current = *stackb;
	target = ft_lstsize(*stackb) - 1;
	while (current && current->index != target)
	{
		top++;
		current = current->next;
	}
	down = ft_lstsize(*stackb) - top;
	while ((*stackb)->index != target)
	{
		if (top <= down)
			rb(stackb);
		else
			rrb(stackb);
	}
	push_a(stacka, stackb);
}

void	ft_sort(t_ps **stacka)
{
	t_ps	*stackb;

	stackb = NULL;
	if (ft_lstsize(*stacka) == 2)
	{
		ft_sort_two(stacka, 'a');
		return ;
	}
	else if (ft_lstsize(*stacka) == 3)
	{
		ft_sort_three(stacka);
		return ;
	}
	ft_indexing(stacka);
	if (ft_lstsize(*stacka) <= 5)
	{
		ft_sort_5nd4(stacka, &stackb);
		return ;
	}
	ft_semi_sort(stacka, &stackb);
	while (stackb)
		ft_final_sort(stacka, &stackb);
	ft_freenode(&stackb);
}
