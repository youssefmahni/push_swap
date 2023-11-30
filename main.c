/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:37:30 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:56 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(void)
{
	system("leaks push_swap");
}
int	main(int ac, char **av)
{
	s_node	*a;
	s_node	*b;

	// atexit(f);
	a = NULL;
	b = NULL;
	av = get_args(ac, av);
	init_stack(&a, av);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	// print_stack(a);
	clear_stack(&a);
	return (0);
}
