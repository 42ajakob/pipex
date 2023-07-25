/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:58:53 by ajakob            #+#    #+#             */
/*   Updated: 2022/11/30 15:06:09 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + 48;
		write(fd, &c, 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		c = n + 48;
		write(fd, &c, 1);
	}
}
