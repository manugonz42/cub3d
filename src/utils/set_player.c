/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:38:15 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:32:51 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_starting_pj_direction(t_game *game, char c)
{
	if (c == 'N')
		game->player->ray = M_PI_2;
	if (c == 'S')
		game->player->ray = 3 * M_PI_2;
	if (c == 'E')
		game->player->ray = 2 * M_PI;
	if (c == 'W')
		game->player->ray = M_PI;
}

void	set_player(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map->matrix;
	y = 0;
	x = 0;
	while (map[y])
	{
		if (ft_strchr(map[y], 'N') || ft_strchr(map[y], 'W') || \
		ft_strchr(map[y], 'E') || ft_strchr(map[y], 'S'))
		{
			x = 0;
			while (map[y][x] != 'N' && map[y][x] != 'S' && \
			map[y][x] != 'E' && map[y][x] != 'W')
				x++;
			break ;
		}
		y++;
	}
	game->player->x = x * TILE_SIZE + TILE_SIZE / 2;
	game->player->y = y * TILE_SIZE + TILE_SIZE / 2;
	set_starting_pj_direction(game, map[y][x]);
}
