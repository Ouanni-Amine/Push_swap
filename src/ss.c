/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:43:56 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:22:47 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps **stacka, t_ps **stackb)
{
	if (stackb && *stackb)
		sb(stackb);
	if (stacka && *stacka)
		sa(stacka);
	ft_putstr_fd("ss\n", 1);
}
