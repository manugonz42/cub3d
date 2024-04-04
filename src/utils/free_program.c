/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:15:40 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:32:22 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx_server, game->mlx_window);
	game->mlx_window = NULL;
	return (0);
}

void	free_sprites(t_game *game)
{
	if (game->sprites->no)
	{
		mlx_destroy_image(game->mlx_server, game->sprites->no->ptr);
		free(game->sprites->no);
	}
	if (game->sprites->so)
	{
		mlx_destroy_image(game->mlx_server, game->sprites->so->ptr);
		free(game->sprites->so);
	}
	if (game->sprites->ea)
	{
		mlx_destroy_image(game->mlx_server, game->sprites->ea->ptr);
		free(game->sprites->ea);
	}
	if (game->sprites->we)
	{
		mlx_destroy_image(game->mlx_server, game->sprites->we->ptr);
		free(game->sprites->we);
	}
	free(game->sprites);
}

int	free_map(t_game *game)
{
	if (game->map->matrix)
		ft_free_matrix(game->map->matrix);
	if (game->map->raw_map)
		free(game->map->raw_map);
	free(game->map);
	return (0);
}

int	free_program(t_game *game)
{
	if (game->player)
		free(game->player);
	if (game->sprites)
		free_sprites(game);
	if (game->frame)
	{
		mlx_destroy_image(game->mlx_server, game->frame->ptr);
		free(game->frame);
	}
	if (game->map)
		free_map(game);
	if (game->mlx_window)
		free_mlx(game);
	if (game->mlx_window)
		printf("Aquí");
//	system("leaks cub3D");
	exit(0);
	return (0);
}
