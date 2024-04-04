/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:23:53 by manugonz          #+#    #+#             */
/*   Updated: 2024/04/04 15:23:54 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**realloc_to_tabs(char **matrix)
{
	int		i;
	int		size;
	char	**new_spc;

	i = 0;
	while (matrix[i])
		i++;
	new_spc = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (matrix[i])
	{
		size = clean_row_size(matrix[i]);
		new_spc[i] = ft_calloc(sizeof(char), size);
		i++;
	}
	return (new_spc);
}

void	add_spcs(char *s, int j)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		s[j] = ' ';
		i++;
		j++;
	}
}

int	clean_row_size(char *line)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			tabs++;
		i++;
	}
	return (i + (tabs * 4) + 1);
}
