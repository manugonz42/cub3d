/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:51:22 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:28:09 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_case(t_game *game, char *path)
{
	if (game->sprites->no->setted)
		err("SPRITES: double assignation of a single sprite", game);
	game->sprites->no->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->no->width, &game->sprites->no->height);
	if (game->sprites->no->ptr == NULL)
		err("SPRITES: no texture found", game);
	game->sprites->no->addr = mlx_get_data_addr(game->sprites->no->ptr,
		&game->sprites->no->bitsinpixel, &game->sprites->no->line_bytes,
		&game->sprites->no->endian);
	game->sprites->no->setted = 1;
}

void	so_case(t_game *game, char *path)
{
	if (game->sprites->so->setted)
		err("SPRITES: double assignation of a single sprite", game);
	game->sprites->so->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->so->width, &game->sprites->so->height);
	if (game->sprites->so->ptr == NULL)
		err("SPRITES: no texture found", game);
	game->sprites->so->addr = mlx_get_data_addr(game->sprites->so->ptr,
		&game->sprites->so->bitsinpixel, &game->sprites->so->line_bytes,
		&game->sprites->so->endian);
	game->sprites->so->setted = 1;
}

void	we_case(t_game *game, char *path)
{
	if (game->sprites->we->setted)
		err("SPRITES: double assignation of a single sprite", game);
	game->sprites->we->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->we->width, &game->sprites->we->height);
	if (game->sprites->we->ptr == NULL)
		err("SPRITES: no texture found", game);
	game->sprites->we->addr = mlx_get_data_addr(game->sprites->we->ptr,
		&game->sprites->we->bitsinpixel, &game->sprites->we->line_bytes,
		&game->sprites->we->endian);
	game->sprites->we->setted = 1;
}

void	ea_case(t_game *game, char *path)
{
	if (game->sprites->ea->setted)
		err("SPRITES: double assignation of a single sprite", game);
	game->sprites->ea->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->ea->width, &game->sprites->ea->height);
	if (game->sprites->ea->ptr == NULL)
		err("SPRITES: no texture found", game);
	game->sprites->ea->addr = mlx_get_data_addr(game->sprites->ea->ptr,
		&game->sprites->ea->bitsinpixel, &game->sprites->ea->line_bytes,
		&game->sprites->ea->endian);
	game->sprites->ea->setted = 1;
}

void	save_texture(char *line, t_game *game, int side, int i)
{
	char	*path;

	path = save_texture_path(line, i, game);
	if (side == NO)
		no_case(game, path);
	else if (side == SO)
		so_case(game, path);
	else if (side == EA)
		ea_case(game, path);
	else if (side == WE)
		we_case(game, path);
	free(path);
}
