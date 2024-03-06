#include "cub3d.h"

void	render_north(t_game *game, t_ray *ray, int n)
{
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;

	ty_off = 0;
	ty_step = 32 / ray->lineH;
	if (ray->lineH > game->height)
	{
		ty_off = (ray->lineH - game->height) / 2;
		ray->lineH = game->height;
	}
	ray->lineO = (game->height / 2) - (ray->lineH / 2);
	tx = 32 - (int)(ray->hx * 4) % 32;
	ty = ty_off * ty_step;
	for (int i = 0; i < ray->lineH; i++)
	{
		for (int j = 0; j < 4; j++)
			*(int *)(game->frame->addr + (i + (int)ray->lineO) * game->frame->line_bytes + n * 16 + 4 * j) = *(int *)(game->sprites->no->addr + ((int)ty * game->sprites->no->line_bytes) + (4 * (int)tx));
		ty += ty_step;
	}
}

void	render_south(t_game *game, t_ray *ray, int n)
{
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;

	ty_off = 0;
	ty_step = 32 / ray->lineH;
	if (ray->lineH > game->height)
	{
		ty_off = (ray->lineH - game->height) / 2;
		ray->lineH = game->height;
	}
	ray->lineO = (game->height / 2) - (ray->lineH / 2);
	tx = (int)(ray->hx * 4) % 32;
	ty = ty_off * ty_step;
	for (int i = 0; i < ray->lineH; i++)
	{
		for (int j = 0; j < 4; j++)
			*(int *)(game->frame->addr + (i + (int)ray->lineO) * game->frame->line_bytes + n * 16 + 4 * j) = *(int *)(game->sprites->so->addr + ((int)ty * game->sprites->no->line_bytes) + (4 * (int)tx));
		ty += ty_step;
	}
}

void	render_east(t_game *game, t_ray *ray, int n)
{
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;

	ty_off = 0;
	ty_step = 32 / ray->lineH;
	if (ray->lineH > game->height)
	{
		ty_off = (ray->lineH - game->height) / 2;
		ray->lineH = game->height;
	}
	ray->lineO = (game->height / 2) - (ray->lineH / 2);
	tx = 32 - (int)(ray->vy * 32 / TILE_SIZE) % 32;
	ty = ty_off * ty_step;
	for (int i = 0; i < ray->lineH; i++)
	{
		for (int j = 0; j < 4; j++)
			*(int *)(game->frame->addr + (i + (int)ray->lineO) * game->frame->line_bytes + n * 16 + 4 * j) = *(int *)(game->sprites->ea->addr + ((int)ty * game->sprites->no->line_bytes) + (4 * (int)tx));
		ty += ty_step;
	}
}

void	render_west(t_game *game, t_ray *ray, int n)
{
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;

	ty_off = 0;
	ty_step = 32 / ray->lineH;
	if (ray->lineH > game->height)
	{
		ty_off = (ray->lineH - game->height) / 2;
		ray->lineH = game->height;
	}
	ray->lineO = (game->height / 2) - (ray->lineH / 2);
	tx = (int)(ray->vy * 4) % 32;
	ty = ty_off * ty_step;
	for (int i = 0; i < ray->lineH; i++)
	{
		for (int j = 0; j < 4; j++)
			*(int *)(game->frame->addr + (i + (int)ray->lineO) * game->frame->line_bytes + n * 16 + 4 * j) = *(int *)(game->sprites->we->addr + ((int)ty * game->sprites->no->line_bytes) + (4 * (int)tx));
		ty += ty_step;
	}
}

void	render_ray(t_game *game, t_ray *ray, int n)
{
	float	angle;

	angle = game->player->ray - ray->ra;
	angle = adjust_angle(angle);
	ray->lineH = (TILE_SIZE * game->height) / (ray->disT * cos(angle));
	if (ray->disT == ray->disH)
	{
		if (ray->ra > M_PI)
			render_north(game, ray, n);
		else
			render_south(game, ray, n);
	}
	else
	{
		if (ray->ra > M_PI_2 && ray->ra < M_PI_3)
			render_west(game, ray, n);
		else
			render_east(game, ray, n);
	}	
}
