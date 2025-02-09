/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semi_sort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:03:58 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/09 15:09:15 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_range(t_ps **stacka)
{
	int	range;

	if (ft_lstsize(*stacka) > 100)
		range = 37;
	else
		range = 11;
	return (range);
}

void	ft_semi_sort_complete(t_ps **stacka, int pattern)
{
	if (pattern == 1)
		rra(stacka);
	else
		ra(stacka);
}

int	ft_patterns_check2(t_ps *stacka, int peak, int up, int direction)
{
	int		len;

	len = ft_lstsize(stacka);
	while (stacka && (stacka)->next)
	{
		if ((stacka)->index < (stacka)->next->index)
		{
			if (direction == -1)
				return (0);
			up++;
			direction = 1;
		}
		else
		{
			if (direction == 1)
				peak = 1;
			direction = -1;
		}
		(stacka) = (stacka)->next;
	}
	if (peak && (up > len / 4))
		return (1);
	return (0);
}
