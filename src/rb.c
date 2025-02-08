/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:31:54 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:13:39 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_ps **stackb)
{
	t_ps	*lst;

	if (!stackb || !*stackb)
		return ;
	lst = *stackb;
	*stackb = (*stackb)->next;
	lst->next = NULL;
	ft_lstadd_back(stackb, lst);
	ft_putstr_fd("rb\n", 1);
}
