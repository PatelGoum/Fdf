/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:33:17 by maguerin          #+#    #+#             */
/*   Updated: 2024/06/03 18:23:31 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isfromset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (isfromset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (isfromset(s1[end], set))
		end--;
	trim = ft_substr(s1, start, (end - start + 1));
	if (!trim)
		return (NULL);
	return (trim);
}

static int	isfromset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
