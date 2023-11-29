CC = cc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror -g
RM = rm -f
# ******************
SRCS = main.c forstring/ps_split.c forstring/ps_atoi.c forstack/init.c forstack/tools.c forgarbage/cleaners.c rules/push.c rules/reverse_rotate.c rules/rotate.c rules/swap.c forsort/sort_stack.c fornodes/init.c fornodes/tools.c forstring/get_args.c forstring/ps_join.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
# ******************
BSRCS = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c forstring/ps_split.c forstring/ps_atoi.c forstack/init.c forstack/tools.c forgarbage/cleaners.c rules/push.c rules/reverse_rotate.c rules/rotate.c rules/swap.c forsort/sort_stack.c fornodes/init.c fornodes/tools.c forstring/get_args.c forstring/ps_join.c
BOBJS = $(BSRCS:.c=.o)
BNAME = checker
# ******************
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

bonus: $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS)

.PHONY : all clean fclean re