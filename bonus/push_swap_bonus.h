/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:03:56 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/07 17:40:55 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "tools_bonus/get_next_line_bonus.h"

typedef struct s_ps
{
	int			num;
	struct s_ps	*next;
}	t_ps;

typedef struct s_psb
{
	char			*move;
	struct s_psb	*next;
}	t_psb;

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
t_ps	*ft_lstnew(int content);
t_ps	*ft_lstlast(t_ps *lst);
void	ft_lstadd_front(t_ps **lst, t_ps *new);
void	ft_lstadd_back(t_ps **lst, t_ps *new);
void	ft_error(t_ps **head, char **res);
void	push_b(t_ps **stacka, t_ps **stackb);
void	push_a(t_ps **stacka, t_ps **stackb);
void	ra(t_ps **stacka);
void	rb(t_ps **stackb);
void	rr(t_ps **stackb, t_ps **stacka);
void	rra(t_ps **stacka);
void	rrb(t_ps **stackb);
void	rrr(t_ps **stacka, t_ps **stackb);
void	sb(t_ps **stackb);
void	sa(t_ps **stacka);
void	ss(t_ps **stacka, t_ps **stackb);
long	ft_long_atoi(const char *str);
int		is_inrange(char *str);
int		is_dup(t_ps *head, t_ps *new);
int		ft_issorted(t_ps *stack);
void	ft_freenode(t_ps **stack);
void	free_split(char **res);
size_t	ft_strlen(const char *s);
void	ft_clean_exit(t_ps **head, char **res);
void	ft_checker(t_ps **stacka, t_ps **stackb);
int		ft_strcmp(char *s1, char *s2);
void	ft_clean_part2(t_ps **stacka, t_psb **instructions, char *line);
void	ft_freebonus(t_psb **list);
void	ft_lstadd_back_str(t_psb **lst, t_psb *new);
t_psb	*ft_lstlast_str(t_psb *lst);
t_psb	*ft_lstnew_str(char *str);
char	*ft_strtrim(char const *s1, char const *set);

#endif
