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
    
char **ft_split(const char *str, char c);
long ft_atoi(const char *str);
int ft_isdigit(int c);
int ft_isvalid(char *str);
int is_duplicate(s_node **a, long tmp);
void append_node(s_node **a, long tmp, char **av, int free_av);
void init_stack(s_node **a, char **av, int free_av);
void free_exit(s_node **a, char **av, int free_av);
void ft_lstclear(s_node **lst);
void ft_vector_clear(char **v);
void show_lst(s_node *A);
int list_size(s_node *A);
bool stack_sorted(s_node *A);
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

void sort_three(s_node **a);
s_node *find_max(s_node **a);
s_node *find_min(s_node **a);

void set_target_node(s_node *a, s_node *b);
void set_index_median(s_node *a);
void set_price(s_node *a, s_node *b);
void set_cheapest_node(s_node *b);
void init_nodes(s_node *a, s_node *b);

void push_swap(s_node **a, s_node **b);

s_node *find_cheapest_node(s_node *b);
void rotate_both(s_node **a, s_node **b, s_node *cheapest_node);
void move_nodes(s_node **a, s_node **b);