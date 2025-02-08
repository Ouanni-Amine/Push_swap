/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freendclean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:52:40 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/05 17:02:50 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_freenode(t_ps **stack)
{
	t_ps	*next;
	t_ps	*current;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free (res);
	res = NULL;
}

void	ft_error(t_ps **head, char **res)
{
	if (head)
		ft_freenode(head);
	if (res)
		free_split(res);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	ft_clean_exit(t_ps **head, char **res)
{
	if (head)
		ft_freenode(head);
	if (res)
		free_split(res);
	exit (1);
}
