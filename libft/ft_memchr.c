/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:50:33 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:05:57 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)str;
	ch = (unsigned char)c;
	while (len--)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
