/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:31:05 by maguerin          #+#    #+#             */
/*   Updated: 2024/05/29 09:33:30 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	total;

	total = nmemb * size;
	if ((nmemb == 0) || (size == 0))
	{	
		array = malloc(0);
		if (array == NULL)
			return (NULL);
		return (array);
	}
	if (total / size != nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, total);
	return (array);
}
