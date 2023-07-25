/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:29 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:41 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	litsize;

	litsize = ft_strlen(little);
	if (!litsize)
		return ((char *)big);
	while (*big && litsize <= len--)
	{
		if (!ft_strncmp(big, little, litsize))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
