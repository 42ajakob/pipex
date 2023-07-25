/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:59:51 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:03 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memrcpy(void *dst, const void *src, size_t len)
{
	int	i;

	i = (int)len - 1;
	while (i >= 0)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((!dst && !src))
		return (0);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else
		return (memrcpy(dst, src, len));
}
