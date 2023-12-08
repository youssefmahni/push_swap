/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:22 by ymahni            #+#    #+#             */
/*   Updated: 2023/12/04 15:39:34 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1s;
	size_t	s2s;
	char	*join;

	if (s1 == NULL)
		s1 = "";
	s1s = ft_strlen(s1);
	s2s = ft_strlen(s2);
	join = malloc(s1s + s2s + 1);
	if (join)
	{
		ft_strlcpy(join, s1, s1s + 1);
		ft_strlcpy(join + s1s, s2, s2s + 1);
		return (join);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int end)
{
	unsigned int	s_len;
	char			*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (end > s_len - start)
		end = s_len - start - 1;
	sub = (char *)malloc(end + 2);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, end + 1);
	return (sub);
}
