#include "../push_swap.h"

char **get_args(int ac, char **av)
{
    if(ac < 2)
        exit(0);
    char **Res = NULL;
    char **tmp = NULL;
    char **tmp2 = NULL;
    int i = 1;
    while (i < ac)
    {
        tmp = ps_split(av[i++]);
        tmp2 = ps_join(Res, tmp);
        Res = tmp2;
    }
    if (!Res)
        exit(1);
    i = 0;
    while (Res[i])
    {
        ps_atoi(Res[i], NULL, NULL);
        if (!isnumber(Res[i]))
            exit_error(NULL, NULL);
        i++;
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
