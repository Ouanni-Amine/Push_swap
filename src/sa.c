/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:39:45 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:21:18 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps **stacka)
{
	t_ps	*lst;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	lst = *stacka;
	*stacka = (*stacka)->next;
	lst->next = (*stacka)->next;
	(*stacka)->next = lst;
	ft_putstr_fd("sa\n", 1);
}
