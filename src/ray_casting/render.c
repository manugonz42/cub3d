/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:51:56 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 20:16:59 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_north(t_game *game, t_ray *ray, int n)
{
	int	i;
	int	j;

	i = -1;
	ray->ty_off = 0;
	ray->ty_step = 32 / ray->lineh;
	if (ray->lineh > game->height)
	{
		ray->ty_off = (ray->lineh - game->height) / 2;
		ray->lineh = game->height;
	}
	ray->lineo = (game->height / 2) - (ray->lineh / 2);
	ray->tx = 31 - (int)(ray->hx * 4) % 32;
	ray->ty = ray->ty_off * ray->ty_step;
	while (++i < ray->lineh)
	{
		j = -1;
		while (++j < 4)
			*(int *)(game->frame->addr + (i + (int)ray->lineo) \
			* game->frame->line_bytes + n * 16 + 4 * j) = \
			*(int *)(game->sprites->no->addr + ((int)ray->ty * \
			game->sprites->no->line_bytes) + (4 * (int)ray->tx));
		ray->ty += ray->ty_step;
	}
}

void	render_south(t_game *game, t_ray *ray, int n)
{
	int	i;
	int	j;

	i = -1;
	ray->ty_off = 0;
	ray->ty_step = 32 / ray->lineh;
	if (ray->lineh > game->height)
	{
		ray->ty_off = (ray->lineh - game->height) / 2;
		ray->lineh = game->height;
	}
	ray->lineo = (game->height / 2) - (ray->lineh / 2);
	ray->tx = (int)(ray->hx * 4) % 32;
	ray->ty = ray->ty_off * ray->ty_step;
	while (++i < ray->lineh)
	{
		j = -1;
		while (++j < 4)
			*(int *)(game->frame->addr + (i + (int)ray->lineo) \
			* game->frame->line_bytes + n * 16 + 4 * j) = \
			*(int *)(game->sprites->so->addr + ((int)ray->ty * \
			game->sprites->so->line_bytes) + (4 * (int)ray->tx));
		ray->ty += ray->ty_step;
	}
}

void	render_east(t_game *game, t_ray *ray, int n)
{
	int	i;
	int	j;

	i = -1;
	ray->ty_off = 0;
	ray->ty_step = 32 / ray->lineh;
	if (ray->lineh > game->height)
	{
		ray->ty_off = (ray->lineh - game->height) / 2;
		ray->lineh = game->height;
	}
	ray->lineo = (game->height / 2) - (ray->lineh / 2);
	ray->tx = 31 - (int)(ray->vy * 32 / TILE_SIZE) % 32;
	ray->ty = ray->ty_off * ray->ty_step;
	while (++i < ray->lineh)
	{
		j = -1;
		while (++j < 4)
			*(int *)(game->frame->addr + (i + (int)ray->lineo) \
			* game->frame->line_bytes + n * 16 + 4 * j) = \
			*(int *)(game->sprites->ea->addr + ((int)ray->ty * \
			game->sprites->ea->line_bytes) + (4 * (int)ray->tx));
		ray->ty += ray->ty_step;
	}
}

void	render_west(t_game *game, t_ray *ray, int n)
{
	int	i;
	int	j;

	i = -1;
	ray->ty_off = 0;
	ray->ty_step = 32 / ray->lineh;
	if (ray->lineh > game->height)
	{
		ray->ty_off = (ray->lineh - game->height) / 2;
		ray->lineh = game->height;
	}
	ray->lineo = (game->height / 2) - (ray->lineh / 2);
	ray->tx = (int)(ray->vy * 32 / TILE_SIZE) % 32;
	ray->ty = ray->ty_off * ray->ty_step;
	while (++i < ray->lineh)
	{
		j = -1;
		while (++j < 4)
			*(int *)(game->frame->addr + (i + (int)ray->lineo) \
			* game->frame->line_bytes + n * 16 + 4 * j) = \
			*(int *)(game->sprites->we->addr + ((int)ray->ty * \
			game->sprites->we->line_bytes) + (4 * (int)ray->tx));
		ray->ty += ray->ty_step;
	}
}

void	render_ray(t_game *game, t_ray *ray, int n)
{
	float	angle;

	angle = game->player->ray - ray->ra;
	angle = adjust_angle(angle);
	ray->lineh = (TILE_SIZE * game->height) / (ray->dist * cos(angle));
	if (ray->dist == ray->dish)
	{
		if (ray->ra > M_PI)
			render_north(game, ray, n);
		else
			render_south(game, ray, n);
	}
	else
	{
		if (ray->ra > M_PI / 2 && ray->ra < 3 * M_PI / 2)
			render_west(game, ray, n);
		else
			render_east(game, ray, n);
	}
}
