/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:04:34 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/04 14:39:23 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base16(const char *nptr)
{
	char	*nb;
	int		result;
	int		i;

	i = 0;
	nb = ft_strdup(nptr);
	result = 0;
	while (nb[i])
	{
		result *= 16;
		if (ft_isdigit(nb[i]))
			result += nb[i] - '0';
		if (ft_isup(nb[i]) && nb[i] <= 'F')
			result += 10 + nb[i] - 'A';
		if (ft_islow(nb[i]) && nb[i] <= 'f')
			result += 10 + nb[i] - 'a';
		i++;
	}
	free(nb);
	return (result);
}
