#include <stdio.h>
#include <stdlib.h>

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

char **ps_join(char **a, char **b)
{
    if (!a)
        return (b);
    long i = 0;
    long j = 0;
    long len_a = vector_len(a);
    long len_b = vector_len(b);
    char **result = malloc(sizeof(char *) * (len_a + len_b + 1));

    while (i < len_a)
    {
        result[i] = a[i];
        i++;
    }
    while (j < len_b)
    {
        result[i] = b[j];
        i++;
        j++;
    }
    result[i] = NULL;
    return result;
}
