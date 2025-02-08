/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:26:59 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/06 16:46:47 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_ps **stacka, t_ps **stackb)
{
	t_ps	*lst;

	if (!stackb || !*stackb)
		return ;
	lst = *stackb;
	*stackb = (*stackb)->next;
	ft_lstadd_front(stacka, lst);
	ft_putstr_fd("pa\n", 1);
}
