#include "push_swap.h"

int main(int ac, char **av)
{
    s_node  *a;
    s_node *b;

    a = NULL;
    b = NULL;
    av = get_args(ac, av);

    init_stack(&a, av, ac == 2);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else
            push_swap(&a, &b);
    }
    // print_stack(a);
    clear_stack(&a);
    return (0);
}
