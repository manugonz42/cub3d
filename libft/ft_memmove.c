/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:55 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/04 17:44:13 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_revcpy(char *c1, char *c2, size_t n)
{
	int	cont;

	cont = n;
	while (cont > 0)
	{
		c1[cont - 1] = c2[cont - 1];
		cont--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	cont;

	c1 = (char *)dest;
	c2 = (char *)src;
	cont = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		ft_revcpy(c1, c2, n);
	else
	{
		cont = 0;
		while (cont < n)
		{
			c1[cont] = c2[cont];
			cont++;
		}
	}
	return (c1);
}
