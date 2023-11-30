# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 18:53:59 by ymahni            #+#    #+#              #
#    Updated: 2023/11/30 18:58:26 by ymahni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SHARED = forstring/ps_split.c fornodes/tools.c fornodes/init.c forsort/sort_stack.c forstring/get_next_line_utils.c forstring/ps_atoi.c forstack/init.c forstack/tools.c forgarbage/cleaners.c rules/push.c rules/reverse_rotate.c rules/rotate.c rules/swap.c forstring/ps_join.c forstring/get_args.c

SRCS = main.c $(SHARED)
OBJS = $(SRCS:.c=.o)
NAME = push_swap

BSRCS = bonus/checker.c bonus/get_next_line.c $(SHARED)  
BOBJS = $(BSRCS:.c=.o)
BNAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY : all clean fclean re