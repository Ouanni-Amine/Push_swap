/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:38:37 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:29:24 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_ps **stacka, t_ps **stackb)
{
	if (stackb && *stackb && (*stackb)->next)
		rrb(stackb);
	if (stacka && *stacka && (*stacka)->next)
		rra(stacka);
}
