/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:55:12 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:42:31 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int run_program(t_game *game)
{
	game->mlx_window = mlx_new_window(game->mlx_server, game->width,
		game->height, "Cub3D");
	if (!game->mlx_window)
		err("MLX: Failed window initialization", game);
	mlx_hook(game->mlx_window, 2, 1L << 0, press_input, game);
	mlx_hook(game->mlx_window, 3, 1L << 1, release_input, game);
	mlx_loop_hook(game->mlx_server, draw_next_frame, game);
	mlx_hook(game->mlx_window, 17, 0, free_program, game);
	mlx_loop(game->mlx_server);
	return (0);
}

int main(int argc, char **argv)
{
	t_game  game;
	int	 len;

	if (argc != 2)
		err(INVALID_ARGS, NULL);
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(argv[1] + len - 4, ".cub", 4))
		err(INVALID_FORMAT, NULL);
	init_program(&game, argv[1]);
	parse_input(&game);
	set_player(&game);
	run_program(&game);
	return (0);
}