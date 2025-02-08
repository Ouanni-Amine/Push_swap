/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:30:21 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:12:55 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps **stacka)
{
	t_ps	*lst;

	if (!stacka || !*stacka)
		return ;
	lst = *stacka;
	*stacka = (*stacka)->next;
	lst->next = NULL;
	ft_lstadd_back(stacka, lst);
	ft_putstr_fd("ra\n", 1);
}
