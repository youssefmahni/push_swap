/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:42 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/04 15:39:13 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
void	clear_rules(t_rule **a);
void	okko(t_node *a, t_node *b);

#endif
