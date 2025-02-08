/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_part2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:00:46 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/04 17:07:22 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_clean_part2(t_ps **stacka, t_psb **instructions, char *line)
{
	free(line);
	ft_freenode(stacka);
	ft_freebonus(instructions);
	exit (1);
}
