/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:55:16 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/08 13:58:03 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_signs(char **res, t_ps **stacka, int j)
{
	int	k;

	k = 0;
	while (res[j][k])
	{
		if (res[j][0] == '+' || res[j][0] == '-')
			k++;
		if (res[j][k] < '0' || res[j][k] > '9')
			ft_error(stacka, res);
		k++;
	}
}

void	check_params(char **res, t_ps **stacka)
{
	int		j;
	t_ps	*new;

	j = 0;
	new = NULL;
	if (!res)
	{
		ft_freenode(stacka);
		exit(1);
	}
	while (res[j])
	{
		check_signs(res, stacka, j);
		if (!is_inrange(res[j]))
			ft_error(stacka, res);
		new = ft_lstnew((int)ft_long_atoi(res[j]));
		if (!new)
			ft_clean_exit(stacka, res);
		if (is_dup(*stacka, new))
			ft_error(stacka, res);
		ft_lstadd_back(stacka, new);
		j++;
	}
}

void	check_unvalidarg(char *str, t_ps **stacka)
{
	int	y;

	y = 0;
	while (str[y] == ' ')
		y++;
	if (str[y] == '\0')
	{
		ft_freenode(stacka);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**res;
	t_ps	*stacka;

	i = 1;
	res = NULL;
	stacka = NULL;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		check_unvalidarg(argv[i], &stacka);
		res = ft_split(argv[i], ' ');
		check_params(res, &stacka);
		free_split(res);
		i++;
	}
	res = NULL;
	if (ft_issorted(stacka))
		ft_clean_exit(&stacka, res);
	ft_sort(&stacka);
	ft_freenode(&stacka);
}
