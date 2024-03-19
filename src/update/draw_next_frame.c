/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_next_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:52:50 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 20:06:22 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_next_frame(t_game *game)
{
	mlx_clear_window(game->mlx_server, game->mlx_window);
	create_background(game);
	update_player_pos(game);
	update_ray(game);
	cast_rays(game);
	create_minimap(game);
	create_player(game);
	print_frame(game);
	usleep(FPS_30);
	return (0);
}
