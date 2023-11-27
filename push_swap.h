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

//for string
char    **ps_split(const char *str);
long    ps_atoi(char *str);
char    **ps_join(char **a, char **b);
char **get_args(int ac, char **av);

// for stack
void    init_stack(s_node **a, char **av, bool free_av);
void    print_stack(s_node *a);
bool    stack_sorted(s_node *a);
int     stack_len(s_node *a);
s_node  *stack_max(s_node *a);
s_node  *stack_min(s_node *a);
s_node *stack_cheapest(s_node *b);

// for garbage
void    exit_error(s_node **a, char **av, bool free_av);
void    vector_clear(char **v);
void    clear_stack(s_node **a);

// rules
void sa(s_node **a);
void sb(s_node **b);
void ss(s_node **a, s_node **b);
void ra(s_node **a);
void rb(s_node **b);
void rr(s_node **a, s_node **b);
void rra(s_node **a);
void rrb(s_node **b);
void rrr(s_node **a, s_node **b);
void pa(s_node **a, s_node **b);
void pb(s_node **b, s_node **a);

//for sort
void sort_three(s_node **a);
void push_swap(s_node **a, s_node **b);

//for nodes
void set_index_median(s_node *a);
void init_nodes(s_node *a, s_node *b);
void sort_nodes(s_node **a, s_node **b);