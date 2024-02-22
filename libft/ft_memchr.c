/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:14 by manugonz          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:15 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*cast;
	unsigned char	l;
	size_t			cont;

	cont = 0;
	cast = (char *)s;
	l = (unsigned char)c;
	while (cont < n)
	{
		if ((unsigned char)cast[cont] == l)
			return (cast + cont);
		cont++;
	}
	return (NULL);
}
