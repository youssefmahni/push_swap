/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:32 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:56:55 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

static void	append_rule(rule **a, char *action)
{
	rule	*new;
	rule	*tmp;

	tmp = NULL;
	if (!a)
		return ;
	new = malloc(sizeof(rule));
	if (!new)
	{
		clear_rules(a);
		write(2, "Error\n", 6);
		exit(1);
	}
	new->action = ft_strdup(action);
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static int	perform_rules_help(s_node **a, s_node **b, rule *rules)
{
	if (ft_strcmp(rules->action, "sa\n"))
		sa(a, 0);
	else if (ft_strcmp(rules->action, "sb\n"))
		sb(b, 0);
	else if (ft_strcmp(rules->action, "ss\n"))
		ss(a, b, 0);
	else if (ft_strcmp(rules->action, "ra\n"))
		ra(a, 0);
	else if (ft_strcmp(rules->action, "rb\n"))
		rb(b, 0);
	else if (ft_strcmp(rules->action, "rr\n"))
		rr(a, b, 0);
	else if (ft_strcmp(rules->action, "rra\n"))
		rra(a, 0);
	else if (ft_strcmp(rules->action, "rrb\n"))
		rrb(b, 0);
	else
		return (0);
	return (1);
}

static void	perform_rules(s_node **a, s_node **b, rule **rules)
{
	rule	*tmp;

	tmp = *rules;
	while (tmp)
	{
		if (perform_rules_help(a, b, tmp))
			write(1, "nothing", 0);
		else if (ft_strcmp(tmp->action, "rrr\n"))
			rrr(a, b, 0);
		else if (ft_strcmp(tmp->action, "pa\n"))
			pa(a, b, 0);
		else if (ft_strcmp(tmp->action, "pb\n"))
			pb(b, a, 0);
		else
		{
			clear_rules(rules);
			clear_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		tmp = tmp->next;
	}
}

static void	get_rules(char **line, rule **rules)
{
	while (*line)
	{
		append_rule(rules, *line);
		free(*line);
		*line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	s_node	*a;
	s_node	*b;
	rule	*rules;
	char	*line;

	a = NULL;
	b = NULL;
	rules = NULL;
	av = get_args(ac, av);
	line = get_next_line(0);
	if (!line)
	{
		vector_clear(av);
		write(2, "KO\n", 3);
		return (1);
	}
	get_rules(&line, &rules);
	init_stack(&a, av);
	perform_rules(&a, &b, &rules);
	okko(a, b);
	clear_rules(&rules);
	clear_stack(&a);
	return (0);
}
