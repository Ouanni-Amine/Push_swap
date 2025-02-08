/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:25:46 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:28:51 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_b(t_ps **stacka, t_ps **stackb)
{
	t_ps	*lst;

	if (!stacka || !*stacka)
		return ;
	lst = *stacka;
	*stacka = (*stacka)->next;
	ft_lstadd_front(stackb, lst);
}
