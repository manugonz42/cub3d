/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:41 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/04 17:43:33 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cd;
	char	*cs;
	size_t	cont;

	cd = (char *)dest;
	cs = (char *)src;
	if (!cd && !cs)
		return (NULL);
	cont = 0;
	while (cont < n)
	{
		cd[cont] = cs[cont];
		cont++;
	}
	return (cd);
}
