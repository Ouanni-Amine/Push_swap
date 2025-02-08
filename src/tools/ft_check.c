/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:18 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/05 16:56:41 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_inrange(char *str)
{
	int		i;
	long	z;

	i = 0;
	while (str[i] == '-' || str[i] == '0' || str[i] == '+')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	z = ft_long_atoi(str);
	if (z > 2147483647 || z < -2147483648)
		return (0);
	else
		return (1);
}

int	is_dup(t_ps *head, t_ps *new)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->num == new->num)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_issorted(t_ps *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
