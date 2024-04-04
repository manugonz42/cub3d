/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:41:53 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 13:53:34 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_case(t_game *game, int y, int x, int color)
{
	int	dy;
	int	dx;
	int	pixel_index;

	dy = 0;
	while (dy < 8)
	{
		dx = 0;
		while (dx < 8)
		{
			pixel_index = ((y * TILE_SIZE) + dy) * game->frame->line_bytes
				+ ((x * TILE_SIZE) + dx) * (game->frame->bitsinpixel / 8);
			*(int *)(game->frame->addr + pixel_index) = color;
			dx++;
		}
		dy++;
	}
}

void	create_minimap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (x < (int)ft_strlen(game->map->matrix[y]) && \
				game->map->matrix[y][x] == '1')
				minimap_case (game, y, x, create_trgb(0, 0, 0, 0));
			else if (x < (int)ft_strlen(game->map->matrix[y]) && \
				!ft_isspace(game->map->matrix[y][x]))
				minimap_case(game, y, x, create_trgb(0, 255, 255, 255));
			x++;
		}
		y++;
	}
}
