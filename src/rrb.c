/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:36:15 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:19:30 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_ps **stackb)
{
	t_ps	*lst;
	t_ps	*last;

	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	last = ft_lstlast(*stackb);
	lst = *stackb;
	while (lst->next && lst->next->next)
		lst = lst->next;
	lst->next = NULL;
	ft_lstadd_front(stackb, last);
	ft_putstr_fd("rrb\n", 1);
}
