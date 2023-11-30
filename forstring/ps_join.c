/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:28 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:29 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/get_next_line.h"
#include "../push_swap.h"

static long	vector_len(char **str)
{
	long	i;

	i = 0;
	while (str && *str)
	{
		str++;
		i++;
	}
	return (i);
}

static void	clear_a_b(char **a, char **b)
{
	vector_clear(a);
	vector_clear(b);
}

char	**ps_join(char **a, char **b)
{
	long	i;
	long	j;
	char	**result;

	if (!a)
		return (b);
	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (vector_len(a) + vector_len(b) + 1));
	if (!result)
	{
		clear_a_b(a, b);
		return (NULL);
	}
	while (i < vector_len(a))
	{
		result[i] = ft_strdup(a[i]);
		i++;
	}
	while (j < vector_len(b))
		result[i++] = ft_strdup(b[j++]);
	result[i] = NULL;
	clear_a_b(a, b);
	return (result);
}
