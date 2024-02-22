/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:28 by manugonz          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:29 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	cont;

	cont = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (cont < n)
	{
		if ((unsigned char)c1[cont] != (unsigned char)c2[cont])
			return ((unsigned char)c1[cont] - (unsigned char)c2[cont]);
		cont++;
	}
	return (0);
}
