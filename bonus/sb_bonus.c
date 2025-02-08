/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:42:51 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:29:33 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_ps **stackb)
{
	t_ps	*lst;

	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	lst = *stackb;
	*stackb = (*stackb)->next;
	lst->next = (*stackb)->next;
	(*stackb)->next = lst;
}
