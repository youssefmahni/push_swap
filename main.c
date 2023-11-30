#include "push_swap.h"

void f()
    {
        system("leaks push_swap");
    }
int main(int ac, char **av)
{
    s_node  *a;
    s_node *b;
// atexit(f);
    a = NULL;
    b = NULL;
    av = get_args(ac, av);
    init_stack(&a, av);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, 1);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else
            push_swap(&a, &b);
    }
    // print_stack(a);
    clear_stack(&a);
    return (0); 
}
