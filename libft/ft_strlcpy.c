/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:49:20 by manugonz          #+#    #+#             */
/*   Updated: 2023/02/20 16:49:22 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cont;

	cont = 0;
	if (size > 0)
	{	
		while (src[cont] && cont < size - 1)
		{
			dest[cont] = src[cont];
			cont++;
		}
		dest[cont] = 0;
	}
	while (src[cont])
		cont++;
	return (cont);
}
