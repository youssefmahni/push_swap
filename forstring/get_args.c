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

bool ft_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    while (s1[i] || s2[i])
    {
        if ((char)s1[i] != (char)s2[i])
            return (0);
        i++;
    }
    return (1);
}