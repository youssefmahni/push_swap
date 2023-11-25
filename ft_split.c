#include "push_swap.h"

static int	c_w(const char *str, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] != c)
		{
			counter++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counter + 1);
}

static int	l_w(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i + 1);
}

static char	*m_w(const char *str, char c)
{
	int		i;
	int		l;
	char	*word;

	i = 0;
	l = l_w(str, c);
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

char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	char	**strs;

	i = 0;
	j = 0;
	strs = (char **) malloc((c_w(str, c) + 1) * sizeof(char *));
	if (!strs || !str)
		return (NULL);
	strs[j++] = "";
	while (str[i])
	{
		if (str[i] != c)
		{
			strs[j++] = m_w(&str[i], c);
			if (!strs[j - 1])
				return (ft_free(strs, j - 1));
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
