/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:50:05 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/21 20:27:48 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
