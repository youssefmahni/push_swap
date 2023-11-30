#include "../bonus/get_next_line.h"
#include "../push_swap.h"

static long vector_len(char **str)
{
    long i = 0;
    while (str && *str)
    {
        str++;
        i++;
    }
    return i;
}

static void clear_a_b(char **a, char **b)
{
    vector_clear(a);
    vector_clear(b);
}

char **ps_join(char **a, char **b)
{
    if (!a)
        return (b);
    long i = 0;
    long j = 0;
    long len_a = vector_len(a);
    long len_b = vector_len(b);
    char **result = malloc(sizeof(char *) * (len_a + len_b + 1));
    if (!result)
    {
        clear_a_b(a, b);
        return (NULL);
    }
    while (i < len_a)
    {
        result[i] = ft_strdup(a[i]);
        i++;
    }
    while (j < len_b)
        result[i++] = ft_strdup(b[j++]);
    result[i] = NULL;
    clear_a_b(a, b);
    return result;
}
