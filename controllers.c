#include "push_swap.h"

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

void ra(s_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(s_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(s_node **a, s_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

static void reverse_rotate(s_node **head)
{
    if (!head || !(*head) || !(*head)->next)
        return ;
    
    s_node *last;
    last = *head;
    while (last->next)
        last = last->next;
    last->prev->next = NULL;
    last->next = *head;
    *head = last;
    last->prev = NULL;
}

void rra(s_node **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(s_node **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(s_node **a, s_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}

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

void pa(s_node **a, s_node **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(s_node **b, s_node **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}

