#include "../push_swap.h"

static void reverse_rotate(s_node **head)
{
    if (!head || !(*head) || !(*head)->next)
        return ;
    s_node *last; 
    last = *head; 
    s_node *second_last; 
    second_last = NULL; 
    while (last->next) 
    { 
        second_last = last; 
        last = last->next; 
    } 
    second_last->next = NULL; 
    last->next = *head; 
    *head = last; 
}

void rra(s_node **a, bool print)
{
    reverse_rotate(a);
    if (print)
        write(1, "rra\n", 4);
}

void rrb(s_node **b, bool print)
{
    reverse_rotate(b);
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(s_node **a, s_node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (print)
        write(1, "rrr\n", 4);
}
