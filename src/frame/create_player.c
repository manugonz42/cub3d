/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:49:44 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:10:57 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_player(t_game *game)
{
	int	k;
	int	l;

	k = 0;
	while (k < 2)
	{
		l = 0;
		while (l < 2)
		{
			*(int *)(game->frame->addr + ((int)game->player->y +
			TILE_SIZE + l) * game->frame->line_bytes + (int)game->player->x
			* 4 + k + 31) = create_trgb(0, 255, 0, 0);
			l++;
		}
		k++;
	}
}
