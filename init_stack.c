#include "push_swap.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_isvalid(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-') // add check for + sign
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_duplicate(s_node **a, long tmp)
{
    s_node *tmp2;

    tmp2 = *a;
    while (tmp2)
    {
        if (tmp2->value == tmp)
            return (1);
        tmp2 = tmp2->next;
    }
    return (0);
}

void append_node(s_node **a, long tmp, char **av, int free_av)
{
    s_node *new;
    s_node *tmp2;

    if (!a)
        return;
    new = malloc(sizeof(s_node));
    if (!new)
        free_exit(a, av, free_av);
    new->value = tmp;
    new->next = NULL;
    new->prev = NULL;
    if (!*a)
        *a = new;
    else
    {
        tmp2 = *a;
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = new;
        new->prev = tmp2;
    }
}

void init_stack(s_node **a, char **av, int free_av)
{

    long tmp;
    int i = 0;
    while (av[i])
    {
        if (!ft_isvalid(av[i]))
            free_exit(a, av - 1, free_av);
        tmp = ft_atoi(av[i]);
        if (tmp > INT_MAX || tmp < INT_MIN)
            free_exit(a, av - 1, free_av);
        if (is_duplicate(a, tmp))
            free_exit(a, av - 1, free_av);
        append_node(a, tmp, av, free_av);
        i++;
    }
    if (free_av)
        ft_vector_clear(av - 1);
}
