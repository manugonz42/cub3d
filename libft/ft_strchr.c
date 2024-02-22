/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:36 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/06 20:30:25 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cont;
	char	*cast;

	cast = (char *)s;
	cont = 0;
	while (cast[cont])
	{
		if (cast[cont] == (char)c)
			return (cast + cont);
		cont++;
	}
	if ((char)c == '\0')
		return (cast + cont);
	return (NULL);
}
