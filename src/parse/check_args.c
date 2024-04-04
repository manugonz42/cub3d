/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:33:08 by manugonz          #+#    #+#             */
/*   Updated: 2024/04/04 15:33:09 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_nline(t_game *game, char *line, int *in_map)
{
	char	*cpy;

	cpy = line;
	ft_skip_spaces(&cpy);
	if (cpy[0] == '1')
	{
		if (!all_args_setted(game))
			err("MAP: missing texture or color", game);
		*in_map = 1;
	}
	if (*in_map)
		parse_map_line(line, game);
	else
		parse_line(cpy, game);
	return (1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char	next_t(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (line[i]);
	}
	return (0);
}

int	all_args_setted(t_game *game)
{
	if (!game->sprites->c->setted || !game->sprites->f->setted
		|| !game->sprites->no->setted || !game->sprites->so->setted
		|| !game->sprites->we->setted || !game->sprites->ea->setted)
		return (0);
	return (1);
}
