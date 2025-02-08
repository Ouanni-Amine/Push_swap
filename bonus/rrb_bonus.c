/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:36:15 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/07 17:40:15 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}
