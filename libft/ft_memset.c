/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:07 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/04 17:41:18 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	size_t			i;

	i = 0;
	cast = (unsigned char *)s;
	while (n > i)
	{
		cast[i] = (unsigned char)c;
		i++;
	}
	return (cast);
}
