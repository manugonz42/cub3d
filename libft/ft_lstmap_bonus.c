/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:44:42 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/08 21:53:40 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nodo;
	t_list	*back;

	if (!lst || !f || !del)
		return (NULL);
	nodo = ft_lstnew(f(lst->content));
	if (!nodo)
		return (NULL);
	back = nodo;
	lst = lst->next;
	while (lst)
	{
		nodo->next = ft_lstnew(f(lst->content));
		if (!nodo)
		{
			ft_lstclear(&back, del);
			return (NULL);
		}
		lst = lst->next;
		nodo = nodo->next;
	}
	nodo->next = NULL;
	return (back);
}
