/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:46 by manugonz          #+#    #+#             */
/*   Updated: 2023/02/20 16:48:48 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	cont;

	cont = 0;
	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!str || !s)
		return (NULL);
	while (s[cont])
	{
		str[cont] = s[cont];
		cont++;
	}
	str[cont] = 0;
	return (str);
}
