/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creation_need.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:53:10 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/06 12:24:44 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_creation_need(char const *s, size_t i, char *c)
{
	if (i == 0)
	{
		if (!ft_strchr(c, s[i]))
			return (1);
	}
	if (!ft_strchr(c, s[i]) && ft_strchr(c, s[i - 1]))
		return (1);
	return (0);
}
