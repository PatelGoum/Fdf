/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:09:08 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/06 12:29:46 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_new_len(char const *s, char *c);
static void		ft_get_free(char **s, size_t i);
int				ft_creation_need(char const *s, size_t i, char *c);

char	**ft_split(char const *s, char *c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (ft_creation_need(s, j, c))
		{
			result[i] = ft_substr(s, j, ft_new_len(&s[j], c));
			if (!result[i])
				return (ft_get_free(result, i), NULL);
			i++;
		}
		j++;
	}
	result[i] = NULL;
	return (result);
}

static size_t	ft_new_len(char const *s, char *c)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (s[count])
	{
		i = 0;
		while (i < ft_strlen(c))
		{
			if (s[count] != c[i])
				i++;
			else
				return (count);
		}
		count++;
	}
	return (count);
}

static void	ft_get_free(char **s, size_t i)
{
	while (i)
	{
		free(s[i]);
		i--;
	}
	free(s[0]);
	free(s);
}
