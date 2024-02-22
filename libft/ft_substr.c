/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:45 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/08 20:28:39 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*r;

	j = (int)start;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		j = ft_strlen(s);
	if (len > ft_strlen(s + (int)j))
		len = ft_strlen(s + (int)j);
	r = (char *)malloc(sizeof(*s) * (len + 1));
	if (!r)
		return (NULL);
	while (i < len && s[j])
	{
		r[i] = s[j];
		j++;
		i++;
	}
	r[i] = 0;
	return (r);
}
