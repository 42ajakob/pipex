/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:37:13 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:18 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}
