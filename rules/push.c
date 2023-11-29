#include "../push_swap.h"

static void push(s_node **dst, s_node **src)
{
    if (!src || !dst || !(*src))
        return ;
    s_node *tmp;
    tmp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    tmp->next = *dst;
    if (*dst)
        (*dst)->prev = tmp;
    *dst = tmp;
}

void pa(s_node **a, s_node **b, bool print)
{
    push(a, b);
    if (print)
        write(1, "pa\n", 3);
}

void pb(s_node **b, s_node **a, bool print)
{
    push(b, a);
    if (print)
        write(1, "pb\n", 3);
}
