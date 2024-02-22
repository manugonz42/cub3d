/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:39:07 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/08 21:48:51 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*b;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		b = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = b;
	}
	*lst = NULL;
}
