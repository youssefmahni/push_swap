#include "push_swap.h"

s_node *find_cheapest_node(s_node *b)
{
    s_node *tmp;
    

    tmp = b;
    while (tmp)
    {
        if (tmp->chepest)
            return (tmp);
        tmp = tmp->next;
    }
    return (b);
}

void rotate_both(s_node **a, s_node **b, s_node *cheapest_node)
{
    while (*a != cheapest_node->target && *b != cheapest_node)
        rr(a, b);
    set_index_median(*a); //maybe not needed
    set_index_median(*b);
}

void reverse_rotate_both(s_node **a, s_node **b, s_node *cheapest_node)
{
    while (*a != cheapest_node->target && *b != cheapest_node)
        rrr(a, b);
    set_index_median(*a);
    set_index_median(*b);
}

void finish_rotation_a(s_node **a, s_node *cheapest_node)
{
    while (*a != cheapest_node->target)
    {
        if (cheapest_node->above_median)
            ra(a);
        else
            rra(a);
    }
}

void finish_rotation_b(s_node **b, s_node *cheapest_node)
{
    while (*b != cheapest_node)
    {
        if (cheapest_node->above_median)
            rb(b);
        else
            rrb(b);
    }
}

void move_nodes(s_node **a, s_node **b)
{
    s_node *cheapest_node;

    cheapest_node = find_cheapest_node(*b);
    if (cheapest_node->above_median && cheapest_node->target->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
        reverse_rotate_both(a, b, cheapest_node);
    finish_rotation_a(a, cheapest_node);
    finish_rotation_b(b, cheapest_node);
    puts("haaa");
    pa(a, b);
}