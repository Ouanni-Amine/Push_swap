/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:03:34 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/05 20:26:39 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_signs(char **res, t_ps **stacka, int j)
{
	int	k;

	k = 0;
	while (res[j][k])
	{
		if (res[j][k] == '+' || res[j][k] == '-')
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
	t_ps	*stackb;

	i = 1;
	res = NULL;
	stacka = NULL;
	stackb = NULL;
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
	ft_checker(&stacka, &stackb);
}
