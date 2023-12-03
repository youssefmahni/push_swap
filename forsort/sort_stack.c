/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:07 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:08 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void basic_sort(t_node **a, t_node **b)
{
	int a_len;

	a_len = stack_len(*a);
	while (a_len-- > 0)
	{
		if ((*a)->value < a_len / 2)
			ra(a, 1);
		else
			pb(b, a, 1);
	}
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		a_len;

	basic_sort(a, b);
	a_len = stack_len(*a);
	while (a_len-- > 3)
		pb(b, a, 1);
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

void	okko(t_node *a, t_node *b)
{
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
