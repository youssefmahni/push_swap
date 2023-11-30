/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:01 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:02 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rr(a, b, 1);
	set_index_median(*a);
	set_index_median(*b);
}

static void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rrr(a, b, 1);
	set_index_median(*a);
	set_index_median(*b);
}

static void	finish_rotation_a(t_node **a, t_node *cheapest_node)
{
	while (*a != cheapest_node->target)
	{
		if (cheapest_node->target->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

static void	finish_rotation_b(t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node)
	{
		if (cheapest_node->above_median)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void	sort_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = stack_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation_a(a, cheapest_node);
	finish_rotation_b(b, cheapest_node);
	pa(a, b, 1);
}
