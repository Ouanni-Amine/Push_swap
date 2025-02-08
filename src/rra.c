/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:35:15 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:17:56 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps **stacka)
{
	t_ps	*last;
	t_ps	*lst;

	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	last = ft_lstlast(*stacka);
	lst = *stacka;
	while (lst->next && lst->next->next)
		lst = lst->next;
	lst->next = NULL;
	ft_lstadd_front(stacka, last);
	ft_putstr_fd("rra\n", 1);
}
