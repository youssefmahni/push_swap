/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:19 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:20 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	validate_arg(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		ps_atoi(res[i], NULL, NULL);
		if (!isnumber(res[i]))
			exit_error(NULL, NULL);
		i++;
	}
}

char	**get_args(int ac, char **av)
{
	char	**res;
	char	**tmp;
	char	**tmp2;
	int		i;

	if (ac < 2)
		exit(0);
	res = NULL;
	tmp = NULL;
	tmp2 = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ps_split(av[i++]);
		tmp2 = ps_join(res, tmp);
		res = tmp2;
	}
	if (!res)
		exit(1);
	validate_arg(res);
	return (res);
}

bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((char)s1[i] != (char)s2[i])
			return (0);
		i++;
	}
	return (1);
}
