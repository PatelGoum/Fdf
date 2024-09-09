/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:01:20 by maguerin          #+#    #+#             */
/*   Updated: 2024/06/03 18:21:00 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	i;

	if (!dst && !siz)
		return (siz);
	dst_len = ft_strlen(dst);
	if (dst_len >= siz)
		return (ft_strlen(src) + siz);
	i = 0;
	while (src[i] && (dst_len + i) < (siz - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (ft_strlen(src) + dst_len);
}
