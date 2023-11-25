#include "push_swap.h"

int main(int ac, char **av)
{
    s_node    *a;
    s_node    *b;
    a = NULL;
    b = NULL;
    
    if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
        return (1);
    if (ac == 2)
        av = ft_split(av[1], ' ');
    init_stack(&a, av+1, ac == 2);


    if (!stack_sorted(a))
    {
        if (list_size(a) == 2)
            sa(&a);
        else if (list_size(a) == 3)
            sort_three(&a);
        else
            push_swap(&a, &b);
    }
        
    show_lst(a);
    
    ft_lstclear(&a);
}