/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:39 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/04 15:14:50 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	validate_arg(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		ps_atoi(res[i], NULL, NULL);
		if (!isnumber(res[i]))
			exit_error(NULL, NULL);
		j = i + 1;
		while (res[j])
		{
			if (ft_strcmp(res[i], res[j]))
				exit_error(NULL, NULL);
			j++;
		}
		i++;
	}
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

char	**get_args(int ac, char **av)
{
	char	**res;
	char	**tmp;
	int		i;

	if (ac < 2)
		exit(0);
	res = NULL;
	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ps_split(av[i++]);
		if (!tmp[0])
		{
			vector_clear(tmp);
			exit_error(NULL, res);
		}
		res = ps_join(res, tmp);
	}
	if (!res)
		exit(1);
	validate_arg(res);
	return (res);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size > 0)
	{
		index = -1;
		while (src[++index] && index < (size))
			dst[index] = src[index];
		dst[index] = '\0';
	}
}
