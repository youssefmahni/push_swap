#include "push_swap.h"

void set_target_node(s_node *a, s_node *b)
{
    s_node *tmp;
    s_node *target;
    long long best_match_index;

    while (b)
    {
        best_match_index = LLONG_MAX;
        tmp = a;
        while (tmp)
        {
            if (tmp->value > b->value && tmp->index < best_match_index)
            {
                best_match_index = tmp->index;
                target = tmp;
            }
            tmp = tmp->next;
        }
        if (best_match_index == LLONG_MAX)
            b->target = find_min(&a);
        else
            b->target = target;
        b = b->next;
    }
}

void set_index_median(s_node *a)
{
    int i;
    int median;
    s_node *tmp;

    i = 0;
    tmp = a;
    median = list_size(a) / 2;
    while (tmp)
    {
        tmp->index = i;
        tmp->chepest = 0;
        if (i < median)
            tmp->above_median = 1;
        else
            tmp->above_median = 0;
        tmp = tmp->next;
        i++;
    }
}

void set_price(s_node *a, s_node *b)
{
    int a_len = list_size(a);
    int b_len = list_size(b);

    while (b)
    {
        b->push_cost = b->index;
        if (!(b->above_median))
            b->push_cost = b_len - b->index;
        if (b->target->above_median)
            b->push_cost += b->target->index;
        else
            b->push_cost += a_len - b->target->index;
        b = b->next;
    }
}

void set_cheapest_node(s_node *b)
{
    long long best_price;
    s_node *best_match_node;

    if (!b)
        return;
    best_price = LLONG_MAX;
    while (b)
    {
        if (b->push_cost < best_price)
        {
            best_price = b->push_cost;
            best_match_node = b;
        }
        b = b->next;
    }
    best_match_node->chepest = 1;
}

void init_nodes(s_node *a, s_node *b)
{
    set_index_median(a);
    set_index_median(b);
    set_target_node(a, b);
    set_price(a, b);
    set_cheapest_node(b);
}