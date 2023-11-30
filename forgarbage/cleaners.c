#include "../push_swap.h"
#include "../bonus/get_next_line.h"

void clear_stack(s_node **a)
{
	s_node *tmp;
	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void vector_clear(char **v)
{
	int i;

	i = 0;
	if (!v)
	    return ;
	while (v && v[i])
		free(v[i++]);
	free(v[i]);
	if (v)
		free(v);
}

void exit_error(s_node **a, char **av)
{
	if (av)
		vector_clear(av);
	if (a)
		clear_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void clear_rules(rule **a)
{
	rule *tmp;

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
