SRCS = main.c forstring/ps_split.c forstring/ps_atoi.c forstack/init.c forstack/tools.c forgarbage/cleaners.c rules/push.c rules/reverse_rotate.c rules/rotate.c rules/swap.c forsort/sort_stack.c fornodes/init.c fornodes/tools.c forstring/get_args.c forstring/ps_join.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror -g
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re