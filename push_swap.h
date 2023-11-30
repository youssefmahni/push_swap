#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int value;
    int index;
    int push_cost;
    bool chepest;
    bool above_median;
    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
} s_node;

typedef struct rule
{
    char        *action;
    struct rule *next;
} rule;

//for string
char    **ps_split(const char *str);
long    ps_atoi(char *str, s_node **a, char **av);
char    **ps_join(char **a, char **b);
char    **get_args(int ac, char **av);
bool    ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, unsigned int end);
char	*ft_strjoin(char *s1, char const *s2);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
int     isnumber(char *str);

// for stack
void    init_stack(s_node **a, char **av);
void    print_stack(s_node *a);
bool    stack_sorted(s_node *a);
int     stack_len(s_node *a);
s_node  *stack_max(s_node *a);
s_node  *stack_min(s_node *a);
s_node *stack_cheapest(s_node *b);

// for garbage
void    exit_error(s_node **a, char **av);
void    vector_clear(char **v);
void    clear_stack(s_node **a);
void    clear_rules(rule **a);

// rules
void sa(s_node **a, bool print);
void sb(s_node **b, bool print);
void ss(s_node **a, s_node **b, bool print);
void ra(s_node **a, bool print);
void rb(s_node **b, bool print);
void rr(s_node **a, s_node **b, bool print);
void rra(s_node **a, bool print);
void rrb(s_node **b, bool print);
void rrr(s_node **a, s_node **b, bool print);
void pa(s_node **a, s_node **b, bool print);
void pb(s_node **b, s_node **a, bool print);

//for sort
void sort_three(s_node **a);
void push_swap(s_node **a, s_node **b);
void okko(s_node *a, s_node *b);

//for nodes
void set_index_median(s_node *a);
void init_nodes(s_node *a, s_node *b);
void sort_nodes(s_node **a, s_node **b);