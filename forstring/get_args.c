#include "../push_swap.h"

char **get_args(int ac, char **av)
{
    if(ac < 2)
        exit(1);
    char **Res = NULL;
    char **tmp = NULL;
    char **tmp2 = NULL;
    int i = 1;
    while (i < ac)
    {
        tmp = ps_split(av[i++]);
        tmp2 = ps_join(Res, tmp);
        free(Res);
        Res = tmp2;
    }
    return (Res);
}
