/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:38:37 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:19:48 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_ps **stacka, t_ps **stackb)
{
	if (stackb && *stackb && (*stackb)->next)
		rrb(stackb);
	if (stacka && *stacka && (*stacka)->next)
		rra(stacka);
	ft_putstr_fd("rrr\n", 1);
}
