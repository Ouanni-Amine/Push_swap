/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:30:21 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:29:01 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_ps **stacka)
{
	t_ps	*lst;

	if (!stacka || !*stacka)
		return ;
	lst = *stacka;
	*stacka = (*stacka)->next;
	lst->next = NULL;
	ft_lstadd_back(stacka, lst);
}
