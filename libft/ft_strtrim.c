/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:32 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/08 20:07:14 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char c, char const *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (set[k] == c)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	int		size;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_check(s1[i], set) == 1)
		i++;
	j = len ;
	while (ft_check(s1[j - 1], set) == 1)
		j--;
	if (len - i -(len - j) < 0)
		size = 0;
	else
		size = len - i - (len - j);
	r = ft_substr(s1, i, size);
	return (r);
}
