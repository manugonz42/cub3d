/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:49:09 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/04 19:47:05 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dst && size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	j = dlen;
	i = 0;
	if (dlen < size - 1 && size > 0)
	{
		while (src[i] && j < size - 1)
		{
			dst[j] = (char)src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dlen >= size)
		dlen = size;
	return (dlen + slen);
}
