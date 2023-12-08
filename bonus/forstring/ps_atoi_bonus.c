/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:47:00 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/08 09:22:17 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

long	ps_atoi(char *str, t_node **a, char **av)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((res * sign) > (INT_MAX - (*str - '0')) / 10
			|| (res * sign) < (INT_MIN + (*str - '0')) / 10)
			exit_error(a, av);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
