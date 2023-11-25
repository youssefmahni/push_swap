#include "push_swap.h"

void push_swap(s_node **a, s_node **b)
{
    s_node *smallest;
    int a_len;
    a_len = list_size(*a);

    while (a_len-- > 3)
        pb(a, b);
    sort_three(a);

    while (*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b);
    }
    set_index_median(*a);
    smallest = find_min(a);
    if (smallest->above_median)
        while (*a != smallest)
            ra(a);
    else
        while (*a != smallest)
            rra(a);
}