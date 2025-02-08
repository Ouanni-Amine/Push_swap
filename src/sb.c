/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:42:51 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/07 17:39:19 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_ps **stackb)
{
	t_ps	*lst;

	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	lst = *stackb;
	*stackb = (*stackb)->next;
	lst->next = (*stackb)->next;
	(*stackb)->next = lst;
	ft_putstr_fd("sb\n", 1);
}
