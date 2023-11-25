#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	// else if (*str == '+')
	// 	str++;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (sign * res);
}


void	show_lst(s_node *A)
{
	s_node *a = A;
	printf("| ");
	while (a)
    {
        printf("%d | ", a->value);
        a = a->next;
    }
}

bool	stack_sorted(s_node *A)
{
	if (!A)
		return (1);
	
	while (A->next)
	{
		if (A->value > A->next->value)
			return (0);
		A = A->next;
	}
	return (1);
}

int		list_size(s_node *A)
{
	int i = 0;
	while (A)
	{
		i++;
		A = A->next;
	}
	return (i);
}