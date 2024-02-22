/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:17 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/08 20:03:43 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = s;
	while (*ret)
		ret++;
	if ((char)c == '\0')
		return ((char *)ret);
	while (--ret >= s)
		if ((char)c == *ret)
			return ((char *)ret);
	return (NULL);
}
