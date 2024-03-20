/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:09:50 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:45:44 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx_server = mlx_init();
	if (!game->mlx_server)
		err("MLX: Failed server initialization", game);
	return (0);
}

int	init_map(t_game *game, char *map)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		err("MAP: malloc error", game);
	game->map->path = map;
	game->map->rows = 0;
	game->map->cols = 0;
	game->map->pj = 0;
	game->map->matrix = NULL;
	game->map->tc_matrix = NULL;
	game->map->raw_map = ft_strdup("");
	if (!game->map->raw_map)
		err("MAP: malloc error", game);
	return (0);
}

int	init_sprites(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
		err("SPRITES: malloc error", game);
	game->sprites->no = malloc(sizeof(t_image));
	game->sprites->so = malloc(sizeof(t_image));
	game->sprites->ea = malloc(sizeof(t_image));
	game->sprites->we = malloc(sizeof(t_image));
	game->sprites->f = malloc(sizeof(t_image));
	game->sprites->c = malloc(sizeof(t_image));
	if (!game->sprites->no || !game->sprites->so || !game->sprites->ea
		|| !game->sprites->we || !game->sprites->f || !game->sprites->c)
		err("SPRITES: malloc error", game);
	game->sprites->no->setted = 0;
	game->sprites->so->setted = 0;
	game->sprites->we->setted = 0;
	game->sprites->ea->setted = 0;
	game->sprites->f->setted = 0;
	game->sprites->c->setted = 0;
	return (0);
}

int	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		err("PLAYER: malloc error", game);
	game->player->fov = FOV;
	game->player->x = 0;
	game->player->y = 0;
	game->player->ray = 0;
	game->player->moving = 0;
	game->player->rotating = 0;
	game->player->mov_speed = 1;
	game->player->rot_speed = 6 * DR;
	return (0);
}

int	init_program(t_game *game, char *map)
{
	game->width = GAME_WIDTH;
	game->height = GAME_HEIGHT;
	init_mlx(game);
	game->frame = malloc(sizeof(t_image));
	if (!game->frame)
		err("GAME: malloc error", game);
	game->frame->ptr = mlx_new_image(game->mlx_server, game->width,
		game->height);
	if (!game->frame->ptr)
		err("MLX: image error", game);
	game->frame->addr = mlx_get_data_addr(game->frame->ptr,
		&game->frame->bitsinpixel, &game->frame->line_bytes,
		&game->frame->endian);
	init_map(game, map);
	init_sprites(game);
	init_player(game);
	return (0);
}
