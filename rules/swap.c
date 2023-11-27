#include "../push_swap.h"

static void swap(s_node **head)
{
    if (!head || !(*head) || !(*head)->next)
        return ;
    s_node *tmp;
    tmp = (*head)->next; // tmp = 2
    (*head)->next = tmp->next; // 1->3
    tmp->next = *head; // 2->1
    *head = tmp; // head = 2
}

void sa(s_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(s_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(s_node **a, s_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
