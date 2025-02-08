/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:55:32 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/07 17:39:31 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_ps
{
	int				num;
	int				index;
	struct s_ps		*next;
}	t_ps;

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
int		ft_lstsize(t_ps *lst);
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
void	ft_sort(t_ps **stacka);
void	ft_sort_three(t_ps **stacka);
void	ft_sort_5nd4(t_ps **stacka, t_ps **stackb);
void	ft_sort_two(t_ps **stack, char c);
int		ft_range(t_ps **stacka);
void	ft_semi_sort_complete(t_ps **stacka, int pattern);
int		ft_patterns_check2(t_ps *stacka, int peak, int up, int direction);

#endif
