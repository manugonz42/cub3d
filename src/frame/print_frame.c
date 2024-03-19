/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:39:56 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:10:48 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx_server, game->mlx_window,
		game->frame->ptr, 0, 0);
}
