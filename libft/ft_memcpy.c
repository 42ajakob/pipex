/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:31:36 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:05:59 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < len)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
