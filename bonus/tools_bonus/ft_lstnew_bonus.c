/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:50:05 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:34:14 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_ps	*ft_lstnew(int content)
{
	t_ps	*node;

	node = malloc(sizeof(t_ps));
	if (!node)
		return (NULL);
	node -> num = content;
	node -> next = NULL;
	return (node);
}
