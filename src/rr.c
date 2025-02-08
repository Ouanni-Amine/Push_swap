/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:33:16 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/30 08:54:33 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps **stackb, t_ps **stacka)
{
	if (stackb && *stackb)
		rb(stackb);
	if (stacka && *stacka)
		ra(stacka);
	ft_putstr_fd("rr\n", 1);
}
