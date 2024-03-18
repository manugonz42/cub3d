/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:41:23 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 13:42:17 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_background(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width * game->height)
	{
		if (i < game->width * game->height / 2)
			*(int *)(game->frame->addr + i * 4) = game->sprites->c->rgb;
		else
			*(int *)(game->frame->addr + i * 4) = game->sprites->f->rgb;
		i++;
	}
}
