/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:15 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:16 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_len(t_node *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_node	*stack_min(t_node *a)
{
	t_node	*tmp;
	t_node	*min;

	if (!a)
		return (NULL);
	tmp = a;
	min = a;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*stack_max(t_node *a)
{
	t_node	*tmp;
	t_node	*max;

	if (!a)
		return (NULL);
	tmp = a;
	max = a;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_node	*stack_cheapest(t_node *b)
{
	t_node	*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->chepest)
			return (tmp);
		tmp = tmp->next;
	}
	return (b);
}
