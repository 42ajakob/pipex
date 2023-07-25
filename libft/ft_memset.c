/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:17:29 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:06 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)b;
	ch = (unsigned char)c;
	while (len--)
	{
		*ptr = ch;
		ptr++;
	}
	return (b);
}
