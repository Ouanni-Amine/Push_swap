/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:25:46 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/30 08:55:35 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_ps **stacka, t_ps **stackb)
{
	t_ps	*lst;

	if (!stacka || !*stacka)
		return ;
	lst = *stacka;
	*stacka = (*stacka)->next;
	ft_lstadd_front(stackb, lst);
	ft_putstr_fd("pb\n", 1);
}
