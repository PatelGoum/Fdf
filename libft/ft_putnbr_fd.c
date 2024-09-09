/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:26:06 by maguerin          #+#    #+#             */
/*   Updated: 2024/05/31 11:50:34 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
		write(fd, "0", 1);
	ft_putdigit_fd(n, fd);
}

static void	ft_putdigit_fd(int n, int fd)
{
	char	c;

	if (n > 0)
	{
		ft_putdigit_fd((n / 10), fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}
