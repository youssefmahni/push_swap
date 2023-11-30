/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:32 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/30 18:53:33 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	c_w(const char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str && str[i])
	{
		if (str[i] != ' ')
		{
			counter++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (counter + 1);
}

static int	l_w(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
	}
	return (i + 1);
}

static char	*m_w(const char *str)
{
	int		i;
	int		l;
	char	*word;

	i = 0;
	l = l_w(str);
	word = (char *)malloc(l * sizeof(char));
	if (!word)
		return (NULL);
	while (i < l - 1)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **str, int j)
{
	while (j >= 0)
		free(str[j--]);
	free(str);
	return (NULL);
}

char	**ps_split(const char *str)
{
	int		i;
	int		j;
	char	**strs;

	i = 0;
	j = 0;
	strs = (char **)malloc(c_w(str) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			strs[j++] = m_w(&str[i]);
			if (!strs[j - 1])
				return (ft_free(strs, j - 1));
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
