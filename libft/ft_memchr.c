/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:02:20 by maguerin          #+#    #+#             */
/*   Updated: 2024/06/05 11:02:02 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	character;
	unsigned char	*str;
	size_t			i;

	character = c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == character)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
