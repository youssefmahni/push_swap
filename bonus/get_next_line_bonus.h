/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:42 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/08 11:42:56 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct rule
{
	char			*action;
	struct rule		*next;
}					t_rule;

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_node;

char	*get_next_line(int fd);
void	validate_rule(char *line, t_rule **rules);
void	clear_rules(t_rule **a);
void	okko(t_node *a, t_node *b);
char	**get_args(int ac, char **av);
long	ps_atoi(char *str, t_node **a, char **av);
char	**ps_join(char **a, char **b);
char	*ft_strdup(const char *str);
char	**ps_split(const char *str);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start,
			unsigned int end);
bool	ft_strcmp(const char *s1, const char *s2);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);
void	exit_error(t_node **a, char **av);
void	vector_clear(char **v);
void	clear_stack(t_node **a);
int		isnumber(char *str);
void	init_stack(t_node **a, char **av);
bool	stack_sorted(t_node *a);

#endif
