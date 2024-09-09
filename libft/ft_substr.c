/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:20:21 by maguerin          #+#    #+#             */
/*   Updated: 2024/06/03 18:22:37 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*little;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		size = 0;
	else
		size = ft_strlen(&s[start]);
	if (len < size)
		size = len;
	little = malloc(sizeof(char) * (size + 1));
	if (!little)
		return (NULL);
	i = 0;
	while ((i < size) && s[start + i])
	{
		little[i] = s[start + i];
		i++;
	}
	little[i] = '\0';
	return (little);
}
