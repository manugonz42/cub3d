/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:25:19 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/26 13:25:21 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extract_line(char *next)
{
	int		i;
	char	*res;

	i = 0;
	if (!next[i])
		return (NULL);
	while (next[i] != '\n' && next[i])
		i++;
	if (next[i] == '\n')
		res = ft_calloc(i + 2, sizeof(char));
	else
		res = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (next[i] != '\n' && next[i])
	{
		res[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
		res[i] = '\n';
	return (res);
}
