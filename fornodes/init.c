/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:52:52 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:52:53 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_node(t_node *a, t_node *b)
{
	t_node	*tmp;
	t_node	*target;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->value > b->value && tmp->value < best_match_value)
			{
				best_match_value = tmp->value;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (best_match_value == LONG_MAX)
			b->target = stack_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	set_price(t_node *a, t_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = b_len - b->index;
		if (b->target->above_median)
			b->push_cost += b->target->index;
		else
			b->push_cost += a_len - b->target->index;
		b = b->next;
	}
}

static void	set_cheapest_node(t_node *b)
{
	long	best_price;
	t_node	*best_match_node;
	t_node	*tmp;

	tmp = b;
	if (!b)
		return ;
	best_price = LONG_MAX;
	while (tmp)
	{
		if (tmp->push_cost < best_price)
		{
			best_price = tmp->push_cost;
			best_match_node = tmp;
		}
		tmp = tmp->next;
	}
	best_match_node->cheapest = 1;
}

void	set_index_median(t_node *a)
{
	int		i;
	int		median;
	t_node	*tmp;

	i = 0;
	tmp = a;
	median = stack_len(a) / 2;
	while (tmp)
	{
		tmp->index = i;
		tmp->cheapest = 0;
		if (i <= median)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
		i++;
	}
}

void	init_nodes(t_node *a, t_node *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest_node(b);
}
