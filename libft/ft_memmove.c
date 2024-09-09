/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:19:42 by maguerin          #+#    #+#             */
/*   Updated: 2024/05/29 11:03:43 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	if (src > dest)
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		while (n--)
			ptr_dest[n] = ptr_src[n];
	}
	return (dest);
}
