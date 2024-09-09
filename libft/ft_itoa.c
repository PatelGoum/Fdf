/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:00:22 by maguerin          #+#    #+#             */
/*   Updated: 2024/06/04 10:22:57 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nsizer(int n);

char	*ft_itoa(int n)
{
	char		*number;
	size_t		size;
	long int	nb;

	nb = n;
	size = ft_nsizer(n);
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	number = malloc(sizeof(char) * (size + 1));
	if (!number)
		return (NULL);
	number[size] = '\0';
	while (size--)
	{
		number[size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		number[0] = '-';
	return (number);
}

static size_t	ft_nsizer(int n)
{
	size_t	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}
