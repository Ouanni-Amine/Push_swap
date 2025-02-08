/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:43:56 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:29:38 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_ps **stacka, t_ps **stackb)
{
	if (stackb && *stackb)
		sb(stackb);
	if (stacka && *stacka)
		sa(stacka);
}
