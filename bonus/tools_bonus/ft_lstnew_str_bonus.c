/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:45:07 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/04 17:16:42 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_psb	*ft_lstnew_str(char *str)
{
	t_psb	*node;

	node = malloc(sizeof(t_psb));
	if (!node)
		return (NULL);
	node->move = ft_strdup(str);
	if (!node->move)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}
