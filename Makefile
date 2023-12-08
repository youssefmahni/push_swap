CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c sort_stack.c forstack/tools.c fornodes/init.c fornodes/tools.c rules/push.c rules/reverse_rotate.c rules/rotate.c rules/swap.c forstring/get_args.c forstring/ps_join.c forstring/ps_atoi.c forstring/ps_split.c cleaners.c forstack/init.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

BSRCS = bonus/checker_bonus.c bonus/checker_utils1_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/rules/push_bonus.c bonus/rules/reverse_rotate_bonus.c bonus/rules/rotate_bonus.c bonus/rules/swap_bonus.c bonus/forstring/get_args_bonus.c bonus/forstring/ps_join_bonus.c bonus/forstring/ps_atoi_bonus.c bonus/forstring/ps_split_bonus.c bonus/cleaners_bonus.c bonus/init_bonus.c
BOBJS = $(BSRCS:.c=.o)
BNAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS)

bonus/%.o: bonus/%.c bonus/get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY : all clean fclean re