#include "cub3d.h"

void	draw_colision(t_game *game, int x, int y);
/*
 *	Save the px coordinates of the colision with horizontal lines. Loop can be executed up to how many
 *	rows the map has. Map coordinates are obtained dividing px coordinate by the number of pixels a tile
 *	has (floor rounded). Once a collision is found, the distance between the collision and the player is
 *	calculated and the px coordinates saved.
 */
void	set_hcolision(t_game *game, t_ray *ray)
{
	int	dof;
	int	mx;
	int	my;

	dof = 0;
	while (dof < game->map->rows)
	{
		mx = ((int)(ray->x) >> TILE_BITS);
		my = ((int)(ray->y) >> TILE_BITS);
		if (mx < 0 || my < 0 || mx >= game->map->cols || my >= game->map->rows)
			dof = game->map->rows;
		else if (game->map->matrix[my][mx] == '1')
		{
			dof = game->map->rows;
			ray->disH = ray_dist(game->player->x, game->player->y, ray->x, ray->y);
			ray->hx = ray->x;
			ray->hy = ray->y;
		}
		else
		{
			ray->x += ray->xo;
			ray->y += ray->yo;
			dof += 1;
		}
	}
}

/*
 *	Find posible colisions in horizontal lines (moving up-down). After finding the direction the ray
 *	is facing (up or down), set the posible colision with the limits of the tile the player is at.
 *	Set up the ofset the colision will have for each extra tile moved. In case it goes straight right
 *	or left, no horizontal colision will happen.
 */
void	horizontal_colision(t_game *game, t_ray *ray)
{
	ray->aTan = -1 / tan(ray->ra);
	if (ray->ra < M_PI)
	{
		ray->y = (((int)game->player->y >> TILE_BITS) << TILE_BITS) - 0.0001;
		ray->x = (game->player->y - ray->y) * ray->aTan + game->player->x;
		ray->yo = -TILE_SIZE;
		ray->xo = -(ray->yo) * ray->aTan;
	}
	else if (ray->ra > M_PI)
	{
		ray->y = (((int)game->player->y >> TILE_BITS) << TILE_BITS) + TILE_SIZE;
		ray->x = (game->player->y - ray->y) * ray->aTan + game->player->x;
		ray->yo = TILE_SIZE;
		ray->xo = -(ray->yo) * ray->aTan;
	}
	else if (ray->ra == 0 || ray->ra == M_PI)
		return ;
	set_hcolision(game, ray);
}

/*
 *	Save the px coordinates of the colision with vertical lines. Loop can be executed up to how many
 *	cols the map has. Map coordinates are obtained dividing px coordinate by the number of pixels a tile
 *	has (floor rounded). Once a collision is found, the distance between the collision and the player is
 *	calculated and the px coordinates saved.
 */
void	set_vcolision(t_game *game, t_ray *ray)
{
	int	dof;
	int	mx;
	int	my;

	dof = 0;
	while (dof < game->map->cols)
	{
		mx = ((int)(ray->x) >> TILE_BITS);
		my = ((int)(ray->y) >> TILE_BITS);
		if (mx < 0 || my < 0 || mx >= game->map->cols || my >= game->map->rows)
			dof = game->map->cols;
		else if (game->map->matrix[my][mx] == '1')
		{
			dof = game->map->cols;
			ray->disV = ray_dist(game->player->x, game->player->y, ray->x, ray->y);
			ray->vx = ray->x;
			ray->vy = ray->y;
		}
		else
		{
			ray->x += ray->xo;
			ray->y += ray->yo;
			dof += 1;
		}
	}
}

/*
 *	Find posible colisions in vertical lines (moving right-left). After finding the direction the ray
 *	is facing (right or left), set the posible colision with the limits of the tile the player is at.
 *	Set up the ofset the colision will have for each extra tile moved. In case it goes straight up
 *	or down, no vertical colision will happen.
 */
void	vertical_colision(t_game *game, t_ray *ray)
{
	ray->aTan = -tan(ray->ra);
	if (ray->ra < M_PI_2 || ray->ra > M_PI_3)
	{
		ray->x = (((int)game->player->x >> TILE_BITS) << TILE_BITS) - 0.0001;
		ray->y = (game->player->x - ray->x) * ray->aTan + game->player->y;
		ray->xo = - TILE_SIZE;
		ray->yo = -(ray->xo) * ray->aTan;
	}
	else if (ray->ra > M_PI_2 && ray->ra < M_PI_3)
	{
		ray->x = (((int)game->player->x >> TILE_BITS) << TILE_BITS) + TILE_SIZE;
		ray->y = (game->player->x - ray->x) * ray->aTan + game->player->y;
		ray->xo = TILE_SIZE;
		ray->yo = -(ray->xo) * ray->aTan;
	}
	else if (ray->ra == M_PI_2 || ray->ra == M_PI_3)
		return ;
	set_vcolision(game, ray);
}


void	render_ray(t_game *game, t_ray *ray, int type, int n)
{
	float	lineH;
	float	lineO;
	float	angle;

	angle = game->player->ray - ray->ra;
	angle = adjust_angle(angle);
	if (type == 'H')
	{
		lineH = (TILE_SIZE * game->height) / (ray->disH * cos(angle));
		if (lineH > game->height)
			lineH = game->height;
		lineO = (game->height / 2) - (lineH / 2);
		for (int i = 0; i < (int)lineH; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (ray->ra > M_PI)
					*(int *)(game->frame->addr + (i + (int)lineO) * game->frame->line_bytes + n * 16 + 4 * j ) = create_trgb(0, 255, 0, 0);
				else
					*(int *)(game->frame->addr + (i + (int)lineO) * game->frame->line_bytes + n * 16 + 4 * j ) = create_trgb(0, 255, 0, 0);
			}
		}
	}
	if (type == 'V')
	{
		lineH = (TILE_SIZE * game->height) / (ray->disV * cos(angle));
		if (lineH > game->height)
			lineH = game->height;
		lineO = (game->height / 2) - (lineH / 2);
		for (int i = 0; i < (int)lineH; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (ray->ra > M_PI_2 && ray->ra < M_PI_3)
					*(int *)(game->frame->addr + (i + (int)lineO) * game->frame->line_bytes + n * 16 + 4 * j ) = create_trgb(0, 200, 0, 0);
				else
					*(int *)(game->frame->addr + (i + (int)lineO) * game->frame->line_bytes + n * 16 + 4 * j ) = create_trgb(0, 200, 0, 0);
			}
		}	
	}
}

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		nb_rays;

	nb_rays = 0;
	ray.ra = game->player->ray - FOV / 2 * DR;
	while (nb_rays < FOV * 4)
	{
		ray.disH = 10000000;
		ray.disV = 10000000;
		ray.ra = adjust_angle(ray.ra);
		horizontal_colision(game, &ray);
		vertical_colision(game, &ray);
		if (ray.disH < ray.disV)
			render_ray(game, &ray, 'H', nb_rays);
		else
			render_ray(game, &ray, 'V', nb_rays);
		ray.ra += DR/4;
		nb_rays++;
	}
}
