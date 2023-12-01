/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:07 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:54:08 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			chepest;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_node;

typedef struct rule
{
	char			*action;
	struct rule		*next;
}					t_rule;

char				**ps_split(const char *str);
long				ps_atoi(char *str, t_node **a, char **av);
char				**ps_join(char **a, char **b);
char				**get_args(int ac, char **av);
bool				ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start,
						unsigned int end);
char				*ft_strjoin(char *s1, char const *s2);
void				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strlen(const char *s);
int					isnumber(char *str);
void				validate_rule(char *line, t_rule **rules);

void				init_stack(t_node **a, char **av);
bool				stack_sorted(t_node *a);
int					stack_len(t_node *a);
t_node				*stack_max(t_node *a);
t_node				*stack_min(t_node *a);
t_node				*stack_cheapest(t_node *b);

void				exit_error(t_node **a, char **av);
void				vector_clear(char **v);
void				clear_stack(t_node **a);
void				clear_rules(t_rule **a);

void				sa(t_node **a, bool print);
void				sb(t_node **b, bool print);
void				ss(t_node **a, t_node **b, bool print);
void				ra(t_node **a, bool print);
void				rb(t_node **b, bool print);
void				rr(t_node **a, t_node **b, bool print);
void				rra(t_node **a, bool print);
void				rrb(t_node **b, bool print);
void				rrr(t_node **a, t_node **b, bool print);
void				pa(t_node **a, t_node **b, bool print);
void				pb(t_node **b, t_node **a, bool print);

void				sort_three(t_node **a);
void				push_swap(t_node **a, t_node **b);
void				okko(t_node *a, t_node *b);

void				set_index_median(t_node *a);
void				init_nodes(t_node *a, t_node *b);
void				sort_nodes(t_node **a, t_node **b);