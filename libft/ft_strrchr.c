/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:04:56 by maguerin          #+#    #+#             */
/*   Updated: 2024/05/30 11:28:53 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*result;

	i = ft_strlen(s);
	result = NULL;
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	if (i == 0)
		return (result);
	i--;
	while ((i > 0) && (s[i] != (unsigned char)c))
		i--;
	if (s[i] == (unsigned char)c)
		result = (char *)&s[i];
	return (result);
}
