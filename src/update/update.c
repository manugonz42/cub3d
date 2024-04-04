/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:16:24 by manugonz          #+#    #+#             */
/*   Updated: 2024/04/04 12:16:25 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	new_x_pos(t_game *game)
{
	double	new_x;

	if (game->player->moving == AHEAD)
		new_x = game->player->x - game->player->mov_speed * \
			cos(game->player->ray);
	if (game->player->moving == BACK)
		new_x = game->player->x + game->player->mov_speed * \
			cos(game->player->ray);
	if (game->player->moving == RIGHT)
		new_x = game->player->x - game->player->mov_speed * \
			cos(game->player->ray + M_PI_2);
	if (game->player->moving == LEFT)
		new_x = game->player->x - game->player->mov_speed * \
			cos(game->player->ray - M_PI_2);
	return (new_x);
}

double	new_y_pos(t_game *game)
{
	double	new_y;

	if (game->player->moving == AHEAD)
		new_y = game->player->y - game->player->mov_speed * \
			sin(game->player->ray);
	if (game->player->moving == BACK)
		new_y = game->player->y + game->player->mov_speed * \
			sin(game->player->ray);
	if (game->player->moving == RIGHT)
		new_y = game->player->y - game->player->mov_speed * \
			sin(game->player->ray + M_PI_2);
	if (game->player->moving == LEFT)
		new_y = game->player->y - game->player->mov_speed * \
			sin(game->player->ray - M_PI_2);
	return (new_y);
}

void	update_player_pos(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x;
	new_y = game->player->y;
	if (game->player->moving == 0)
		return ;
	new_x = new_x_pos(game);
	new_y = new_y_pos(game);
	if (game->map->matrix[(int)new_y / TILE_SIZE][(int)new_x / \
		TILE_SIZE] != '1')
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	update_ray(t_game *game)
{
	if (game->player->rotating == 0)
		return ;
	if (game->player->rotating == ROT_LEFT)
		game->player->ray -= game->player->rot_speed;
	if (game->player->rotating == ROT_RIGHT)
		game->player->ray += game->player->rot_speed;
	if (game->player->ray < 0)
		game->player->ray += 2 * M_PI;
	if (game->player->ray > 2 * M_PI)
		game->player->ray -= 2 * M_PI;
}
