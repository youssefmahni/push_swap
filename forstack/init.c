/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:11 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:12 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static bool	is_duplicate(s_node **a, long node_value)
{
	s_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->value == node_value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	append_node(s_node **a, long node_value, char **av)
{
	s_node	*new;
	s_node	*tmp;

	if (!a)
		return ;
	new = malloc(sizeof(s_node));
	if (!new)
		exit_error(a, av);
	new->value = node_value;
	new->next = NULL;
	if (!*a)
	{
		new->prev = NULL;
		*a = new;
	}
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	init_stack(s_node **a, char **av)
{
	long	node_value;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!isnumber(av[i]))
			exit_error(a, av);
		node_value = ps_atoi(av[i], a, av);
		if (is_duplicate(a, node_value))
			exit_error(a, av);
		append_node(a, node_value, av);
		i++;
	}
	vector_clear(av);
}
