/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:22 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/08 19:14:51 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_next_c(char const *s, int c, int m)
{
	while (s[m] && s[m] != c)
		m++;
	return (m);
}

static int	ft_next_word(char const *s, int c, int m)
{
	while (s[m] && s[m] == c)
		m++;
	if (s[m] == '\0')
		return (-1);
	return (m);
}

static int	ft_num_of_str(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[n])
	{
		n = ft_next_word(s, c, n);
		if (n != -1)
			i++;
		else
			return (i);
		n = ft_next_c(s, c, n);
	}
	return (i);
}

static void	ft_free_all(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free (res[i]);
		i++;
	}
	free (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_num_of_str(s, c) + 1));
	if (!res)
		return (NULL);
	while (k < ft_num_of_str(s, c))
	{
		i = ft_next_word(s, c, i);
		res[k] = ft_substr(s, i, ft_next_c(s, c, i) - i);
		if (!res[k])
		{
			ft_free_all(res);
			return (NULL);
		}
		i = ft_next_c(s, c, i);
		k++;
	}
	res[k] = 0;
	return (res);
}
