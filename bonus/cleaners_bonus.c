/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:44:52 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/08 09:21:47 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clear_stack(t_node **a)
{
	t_node	*tmp;

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

void	exit_error(t_node **a, char **av)
{
	if (av)
		vector_clear(av);
	if (a)
		clear_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
