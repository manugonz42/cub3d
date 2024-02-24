#include "cub3d.h"

/*void ray_cast(t_game *game)
{
	int		i;
	double	ray;
	double	angle;
	double	dist;
	double	x;
	double	y;

	i = 0;
	ray = game->player->ray - (FOV / 2);
	while (i < game->res->width)
	{
		angle = ray - game->player->ray;
		dist = 0;
		while (dist < game->res->width)
		{
			x = game->player->x + dist * cos(angle);
			y = game->player->y + dist * sin(angle);
			if (game->map->matrix[(int)y / 8][(int)x / 8] == '1')
				break ;
			dist += 0.1;
		}
		//draw_ray(game, ray, dist);
		ray += (FOV / game->res->width);
		i++;
	}
}*/

void init_ray_cast(t_game *game)
{
	int		horizontal_hit;	
	int		horizontal_x_hit;
	//int		vertical_x_hit;
	int		horizontal_y_hit;
	//int		vertical_y_hit;
	int		up;
	int		left;
	int		y_intercept;
	int		x_intercept;
	int		y_step;
	int		x_step;
	int		next_horizontal_x;
	int		next_horizontal_y;
	//double	adjacent;

	up = 0;
	left = 0;
	horizontal_hit = 0;
	horizontal_x_hit = 0;
	//vertical_x_hit = 0;
	horizontal_y_hit = 0;
	//vertical_y_hit = 0;
	if (game->player->ray > 0 && game->player->ray < M_PI)
		up = 1;
	if (game->player->ray > M_PI_2 && game->player->ray < 3 * M_PI_2)
		left = 1;
	y_intercept = floor(game->player->y / 8) * 8;
	if (!up)
		y_intercept += 8;
	//adjacent = fabs((game->player->y - y_intercept) / tan(game->player->ray));
	y_step = 8;
	if (up)
		y_step *= -1;
	x_step = 8 / tan(game->player->ray);
	if ((!left && x_step < 0) || (left && x_step > 0))
		x_step *= -1;
	x_intercept = game->player->x + (game->player->y - y_intercept) / tan(game->player->ray);
	next_horizontal_x = x_intercept;
	next_horizontal_y = y_intercept;
	if (up)
		next_horizontal_y--;
	while(!horizontal_hit && next_horizontal_x >= 0 && next_horizontal_x < game->width && next_horizontal_y >= 0 && next_horizontal_y < game->height)
	{
		if (game->map->matrix[(int)floor(next_horizontal_y / 8)][(int)floor(next_horizontal_x / 8)] == '1')
		{
			horizontal_hit = 1;
			horizontal_x_hit = next_horizontal_x;
			horizontal_y_hit = next_horizontal_y;
		}
		else
		{
			next_horizontal_x += x_step;
			next_horizontal_y += y_step;
		}
	}
	draw_ray(game->player->x, game->player->y, horizontal_x_hit, horizontal_y_hit, game->frame);	
}
