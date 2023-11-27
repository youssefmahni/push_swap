#include "../push_swap.h"

static int isnumber(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

static bool is_duplicate(s_node **a, long node_value)
{
    s_node *tmp;

    tmp = *a;
    while (tmp)
    {
        if (tmp->value == node_value)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

static void append_node(s_node **a, long node_value, char **av, int free_av)
{
    s_node *new;
    s_node *tmp;

    if (!a)
        return;
    new = malloc(sizeof(s_node));
    if (!new)
        exit_error(a, av, free_av);
    new->value = node_value;
    new->next = NULL;
    if (!*a)
    {
        new->prev = NULL;
        *a = new;
    }
    else
    {
        tmp = *a;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}

void init_stack(s_node **a, char **av, bool free_av)
{
    long node_value;
    int i;

    i = 0;
    while (av[i])
    {
        if (!isnumber(av[i]))
            exit_error(a, av, free_av);
        node_value = ps_atoi(av[i]);
        if (node_value > INT_MAX || node_value < INT_MIN)
            exit_error(a, av, free_av);
        if (is_duplicate(a, node_value))
            exit_error(a, av, free_av);
        append_node(a, node_value, av, free_av);
        i++;
    }
    if (free_av)
        vector_clear(av);
}
