/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:37 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:38 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(s_node **dst, s_node **src)
{
	s_node	*tmp;

	if (!src || !dst || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	pa(s_node **a, s_node **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(s_node **b, s_node **a, bool print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
