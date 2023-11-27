#include "../push_swap.h"

void sort_three(s_node **a)
{
    s_node *max;
    max = stack_max(*a);
    if ((*a)->value == max->value)
        ra(a);
    else if ((*a)->next->value == max->value)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void push_swap(s_node **a, s_node **b)
{
    s_node *smallest;
    int a_len;
    a_len = stack_len(*a);

    while (a_len-- > 3)
        pb(b, a);
    sort_three(a);

    while (*b)
    {
        init_nodes(*a, *b);
        sort_nodes(a, b);
    }
    set_index_median(*a);
    smallest = stack_min(*a);
    if (smallest->above_median)
        while (*a != smallest)
            ra(a);
    else
        while (*a != smallest)
            rra(a);
}