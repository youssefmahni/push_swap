/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:47 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:52:48 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/get_next_line.h"
#include "../push_swap.h"

void	clear_stack(s_node **a)
{
	s_node	*tmp;

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	vector_clear(char **v)
{
	int	i;

	i = 0;
	if (!v)
		return ;
	while (v && v[i])
		free(v[i++]);
	free(v[i]);
	if (v)
		free(v);
}

void	exit_error(s_node **a, char **av)
{
	if (av)
		vector_clear(av);
	if (a)
		clear_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	clear_rules(rule **a)
{
	rule	*tmp;

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
