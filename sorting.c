#include "push_swap.h"

s_node *find_max(s_node **a)
{
    s_node *tmp;
    s_node *max;

    tmp = *a;
    max = *a;
    while (tmp)
    {
        if (tmp->value > max->value)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

s_node *find_min(s_node **a)
{
    s_node *tmp;
    s_node *min;

    tmp = *a;
    min = *a;
    while (tmp)
    {
        if (tmp->value < min->value)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}

void sort_three(s_node **a)
{
    s_node *max;
    max = find_max(a);
    if ((*a)->value == max->value)
        ra(a);
    else if ((*a)->next->value == max->value)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

// void sort_five(s_node **a, s_node **b);