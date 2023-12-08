/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:07 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/04 15:03:25 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*max;

	max = stack_max(*a);
	if ((*a)->value == max->value)
		ra(a, 1);
	else if ((*a)->next->value == max->value)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

static void	basic_sort(t_node **a, t_node **b)
{
	int	a_len;
	int	avg;

	a_len = stack_len(*a);
	avg = a_len / 2;
	while (a_len-- > 0)
	{
		if ((*a)->value < avg)
			ra(a, 1);
		else
			pb(b, a, 1);
	}
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		a_len;

	a_len = stack_len(*a);
	if (a_len > 99)
		basic_sort(a, b);
	a_len = stack_len(*a);
	while (a_len-- > 3)
		pb(b, a, 1);
	if (a_len == 2)
		sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		sort_nodes(a, b);
	}
	set_index_median(*a);
	smallest = stack_min(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}
