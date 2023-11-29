#include "../push_swap.h"

static void rotate(s_node **head)
{
    if (!head || !(*head) || !(*head)->next)
        return ;
    s_node *tmp; 
    tmp = *head;
    *head = (*head)->next;
    tmp->next = NULL; 
    s_node *last; 
    last = *head; 
    while (last->next) 
        last = last->next; 
    last->next = tmp; 
}

void ra(s_node **a, bool print)
{
    rotate(a);
    if (print)
        write(1, "ra\n", 3);
}

void rb(s_node **b, bool print)
{
    rotate(b);
    if (print)
        write(1, "rb\n", 3);
}

void rr(s_node **a, s_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (print)
        write(1, "rr\n", 3);
}