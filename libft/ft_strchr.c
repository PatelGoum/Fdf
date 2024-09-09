/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:24:11 by maguerin          #+#    #+#             */
/*   Updated: 2024/05/30 11:35:43 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i] && (s[i] != (unsigned char)c))
		i++;
	if (s[i] == (unsigned char)c)
		result = (char *) &s[i];
	else
		result = NULL;
	return (result);
}
