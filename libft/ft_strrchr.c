/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:43:32 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:43 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	size_t	n;

	n = ft_strlen(s);
	ch = (char)c;
	str = (char *)s + n;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str--;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}
