/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:48:44 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:05:56 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*convtostr(long n, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[i] = '-';
		i = 1;
	}
	str[len] = '\0';
	len--;
	while (len >= i)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	i;

	len = intlen(n);
	if (n < 0)
		len++;
	i = n;
	str = convtostr(i, len);
	return (str);
}
