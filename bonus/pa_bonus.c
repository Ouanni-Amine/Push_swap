/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:26:59 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:28:46 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_a(t_ps **stacka, t_ps **stackb)
{
	t_ps	*lst;

	if (!stackb || !*stackb)
		return ;
	lst = *stackb;
	*stackb = (*stackb)->next;
	ft_lstadd_front(stacka, lst);
}
