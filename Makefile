SRCS = assassins.c ft_atoi.c ft_split.c init_stack.c main.c controllers.c sorting.c push_swap.c move_nodes.c init_node.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror 
RM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)


clean:
	$(RM) $(NAME)

re: clean all

.PHONY : all clean re