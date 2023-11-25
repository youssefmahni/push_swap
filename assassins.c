#include "push_swap.h"

void ft_lstclear(s_node **lst)
{
	s_node *help;

	while (lst && *lst)
	{
		help = (*lst)->next;
		free(*lst);
		*lst = help;
	}
}

void ft_vector_clear(char **v)
{
	int i;

	i = 1;
	while (v[i])
		free(v[i++]);
	free(v);
}

void free_exit(s_node **a, char **av, int free_av)
{
	if (free_av)
		ft_vector_clear(av);
	if (*a)
		ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}
