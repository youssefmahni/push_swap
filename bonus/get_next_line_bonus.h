/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:42 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 20:57:19 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct rule
{
	char			*action;
	struct rule		*next;
}					t_rule;

char	*get_next_line(int fd);
void	validate_rule(char *line, t_rule **rules);
void    clear_rules(t_rule **a);
void    okko(t_node *a, t_node *b);

#endif
