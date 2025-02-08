src_tools = src/tools/
bonus_tools = bonus/tools_bonus/

dir_src = src/
dir_bonus = bonus/

SRC = $(dir_src)pa.c $(dir_src)pb.c $(dir_src)ra.c $(dir_src)rb.c $(dir_src)rr.c $(dir_src)rra.c \
	$(dir_src)rrb.c $(dir_src)rrr.c $(dir_src)sa.c $(dir_src)sb.c $(dir_src)ss.c \
	$(dir_src)push_swap.c $(dir_src)algo.c

TOOLS_SRC = $(src_tools)ft_long_atoi.c $(src_tools)ft_freendclean.c $(src_tools)ft_lstadd_back.c \
		$(src_tools)ft_lstadd_front.c $(src_tools)ft_lstlast.c $(src_tools)ft_lstnew.c $(src_tools)special_sort.c\
		$(src_tools)ft_lstsize.c $(src_tools)ft_putstr_fd.c $(src_tools)ft_split.c $(src_tools)ft_check.c $(src_tools)ft_semi_sort2.c

BONUS = $(dir_bonus)pb_bonus.c  $(dir_bonus)push_swap_bonus.c $(dir_bonus)ra_bonus.c $(dir_bonus)rb_bonus.c $(dir_bonus)rr_bonus.c\
	 $(dir_bonus)rra_bonus.c $(dir_bonus)rrb_bonus.c $(dir_bonus)rrr_bonus.c $(dir_bonus)sa_bonus.c $(dir_bonus)sb_bonus.c \
	 $(dir_bonus)ss_bonus.c $(dir_bonus)checker_bonus.c $(dir_bonus)pa_bonus.c

TOOLS_BONUS = $(bonus_tools)ft_check_bonus.c $(bonus_tools)ft_clean_part2_bonus.c $(bonus_tools)ft_freendclean_bonus.c $(bonus_tools)ft_long_atoi_bonus.c \
			$(bonus_tools)ft_lstad_back_str_bonus.c $(bonus_tools)ft_lstadd_back_bonus.c $(bonus_tools)ft_lstadd_front_bonus.c $(bonus_tools)ft_lstlast_bonus.c \
			$(bonus_tools)ft_lstlast_str_bonus.c $(bonus_tools)ft_lstnew_bonus.c $(bonus_tools)ft_lstnew_str_bonus.c $(bonus_tools)ft_lstsize_bonus.c \
			$(bonus_tools)ft_putstr_fd_bonus.c $(bonus_tools)ft_split_bonus.c $(bonus_tools)ft_strcmp_bonus.c $(bonus_tools)ft_strtrim_bonus.c \
			$(bonus_tools)get_next_line_bonus.c $(bonus_tools)get_next_line_utils_bonus.c

OBJS = $(SRC:.c=.o)
OBJT = $(TOOLS_SRC:.c=.o)

OBJB = $(BONUS:.c=.o)
OBJBT = $(TOOLS_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS) $(OBJT)
	$(CC) $(CFLAGS) $^ -o $@

$(dir_src)%.o : $(dir_src)%.c $(dir_src)push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(src_tools)%.o : $(src_tools)%.c $(dir_src)push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJB) $(OBJBT)
	$(CC) $(CFLAGS) $^ -o $@

$(dir_bonus)%.o : $(dir_bonus)%.c $(dir_bonus)push_swap_bonus.h $(bonus_tools)get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(bonus_tools)%.o : $(bonus_tools)%.c $(dir_bonus)push_swap_bonus.h $(bonus_tools)get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJT) $(OBJB) $(OBJBT)

fclean:clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY : clean
