/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:13:39 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:13 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countsubstrings(char const *s, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			j++;
		i++;
	}
	if (s[0] != c)
		j++;
	return (j);
}

static int	substrlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*copysubstr(char const *src, int i)
{
	char	*string;

	string = ft_calloc((i + 1), sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, src, i + 1);
	return (string);
}

static void	*freeptr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		count;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	count = countsubstrings(s, c);
	strings = ft_calloc((count + 1), sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (++i < count && s[j])
	{
		while (s[j] == c)
			j++;
		len = substrlen(&s[j], c);
		strings[i] = copysubstr(&s[j], len);
		if (!strings[i])
			return (freeptr(strings));
		j += len;
	}
	strings[count] = NULL;
	return (strings);
}
