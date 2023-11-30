/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:44 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:45 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(s_node **head)
{
	s_node	*tmp;
	s_node	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	ra(s_node **a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(s_node **b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(s_node **a, s_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}