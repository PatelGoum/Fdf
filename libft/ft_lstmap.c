/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:37:42 by maguerin          #+#    #+#             */
/*   Updated: 2024/06/04 10:02:15 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		data = f(lst->content);
		new = ft_lstnew(data);
		if (!new)
		{
			free(data);
			ft_lstclear(&result, (*del));
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
