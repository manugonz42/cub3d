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

void init_ray_cast(t_game *game, double cell_height, double cell_width)
{
	t_ray	*ray_data;

	ray_data = game->player->ray_data;
	ray_data->up = 0;
	ray_data->left = 0;
	ray_data->horizontal_hit = 0;
	ray_data->horizontal_x_hit = 0;
	ray_data->vertical_x_hit = 0;
	ray_data->horizontal_y_hit = 0;
	ray_data->vertical_y_hit = 0;
	//Si el rayo esta entre 0 y 180 grados
	if (game->player->ray > 0 && game->player->ray < M_PI)
		ray_data->up = 1;
	//Si el rayo esta entre 90 y 270 grados
	if (game->player->ray > M_PI_2 && game->player->ray < 3 * M_PI_2)
		ray_data->left = 1;
	//Casilla en la que se intercepta el rayo
	ray_data->y_intercept = floor(game->player->y / cell_height) * cell_height;
	//Si el rayo esta hacia abajo será la siguiente casilla
	if (!ray_data->up)
		ray_data->y_intercept += cell_height;
	ray_data->adjacent = fabs((game->player->y - ray_data->y_intercept) / tan(game->player->ray));
	ray_data->y_step = cell_height;
	if (ray_data->up)
		ray_data->y_step *= -1;
	ray_data->x_step = cell_width / tan(game->player->ray);
	if ((!ray_data->left && ray_data->x_step < 0) || (ray_data->left && ray_data->x_step > 0))
		ray_data->x_step *= -1;
	ray_data->x_intercept = game->player->x + (game->player->y - ray_data->y_intercept) / tan(game->player->ray);
	ray_data->next_horizontal_x = ray_data->x_intercept;
	ray_data->next_horizontal_y = ray_data->y_intercept;
	if (ray_data->up)
		ray_data->next_horizontal_y--;
	while(!ray_data->horizontal_hit && ray_data->next_horizontal_x >= 0 && ray_data->next_horizontal_x < game->width && ray_data->next_horizontal_y >= 0 && ray_data->next_horizontal_y < game->height)
	{
		if (game->map->matrix[(int)floor(ray_data->next_horizontal_y / cell_height)][(int)floor(ray_data->next_horizontal_x / cell_width)] == '1')
		{
			ray_data->horizontal_hit = 1;
			ray_data->horizontal_x_hit = ray_data->next_horizontal_x;
			ray_data->horizontal_y_hit = ray_data->next_horizontal_y;
		}
		else
		{
			ray_data->next_horizontal_x += ray_data->x_step;
			ray_data->next_horizontal_y += ray_data->y_step;
		}
	}
	draw_ray(game->player->x, game->player->y, ray_data->horizontal_x_hit, ray_data->horizontal_y_hit, game->frame);	
}
