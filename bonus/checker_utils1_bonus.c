

#include "get_next_line_bonus.h"

void	validate_rule(char *line, t_rule **rules)
{
	if (!ft_strcmp(line, "sa\n") && !ft_strcmp(line, "sb\n") && 
		!ft_strcmp(line, "ss\n") && !ft_strcmp(line, "pa\n") && 
		!ft_strcmp(line, "pb\n") && !ft_strcmp(line, "ra\n") && 
		!ft_strcmp(line, "rb\n") && !ft_strcmp(line, "rr\n") && 
		!ft_strcmp(line, "rra\n") && !ft_strcmp(line, "rrb\n") && 
		!ft_strcmp(line, "rrr\n"))
	{
		clear_rules(rules);
		free(line);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	clear_rules(t_rule **a)
{
	t_rule *tmp;

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void okko(t_node *a, t_node *b)
{
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}