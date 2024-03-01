#include "cub3d.h"

void	find_next_horizontal_hit(t_game *game, t_ray *ray_data, double cell_height, double cell_width)
{
	//Comprobamos en cada iteración si siguiente linea horizontal pertenece a una pared

	while(!ray_data->horizontal_hit && ray_data->next_horizontal_x >= 0 && ray_data->next_horizontal_x < cell_width * game->map->cols && ray_data->next_horizontal_y >= 0 && ray_data->next_horizontal_y < cell_height * game->map->rows)
	{
		if (game->map->matrix[(int)floor(ray_data->next_horizontal_y / cell_height)][(int)floor(ray_data->next_horizontal_x / cell_width)] == '1')
		{
			//printf("horizontal if: y_step: %f, y_start: %f, next_vertical_y: %f, x_start %f, next_X %f\n", ray_data->y_step, game->player->y, ray_data->next_vertical_y, game->player->x, ray_data->next_vertical_x);
			ray_data->horizontal_hit = 1;
			ray_data->horizontal_x_hit = ray_data->next_horizontal_x;
			ray_data->horizontal_y_hit = ray_data->next_horizontal_y;
		}
		else
		{
			//printf("horizontal while: y_step: %f, y_start: %f, next_vertical_y: %f, x_start %f, next_X %f\n", ray_data->y_step, game->player->y, ray_data->next_vertical_y, game->player->x, ray_data->next_vertical_x);
			ray_data->next_horizontal_x += ray_data->x_step;
			ray_data->next_horizontal_y += ray_data->y_step;
		}
	}
}

void	find_next_vertical_hit(t_game *game, t_ray *ray_data, double cell_height, double cell_width)
{
	//Comprobamos en cada iteración si siguiente linea vertical pertenece a una pared
	while(!ray_data->vertical_hit && ray_data->next_vertical_x >= 0 && ray_data->next_vertical_x < cell_width * game->map->cols && ray_data->next_vertical_y >= 0 && ray_data->next_vertical_y < cell_height * game->map->rows)
	{
		if (game->map->matrix[(int)floor(ray_data->next_vertical_y / cell_height)][(int)floor(ray_data->next_vertical_x / cell_width)] == '1')
		{
			//printf("vertical if: y_step: %f, y_start: %f, next_vertical_y: %f x_start %f, next_X %f\n", ray_data->y_step, game->player->y, ray_data->next_vertical_y, game->player->x, ray_data->next_vertical_x);
			ray_data->vertical_hit = 1;
			ray_data->vertical_x_hit = ray_data->next_vertical_x;
			ray_data->vertical_y_hit = ray_data->next_vertical_y;
		}
		else
		{
			//printf(GREEN"else: y_step: %f, y_start: %f, next_vertical_y: %f\n"WHITE, ray_data->y_step, game->player->y, ray_data->next_vertical_y);
			ray_data->next_vertical_x += ray_data->x_step;
			ray_data->next_vertical_y += ray_data->y_step;
		}
	}
}

void	set_horizontal_vars(t_game *game, t_ray *ray_data, double cell_height, double cell_width)
{
	double	ray_angle;

	printf("player x: %f, y: %f\n", game->player->x, game->player->y);
	//printf("horizntal player angle: %f\n", game->player->ray);
	ray_angle = game->player->ray;
	/*if (ray_angle == 0 || ray_angle == M_PI)
		ray_angle = INT_MAX;*/
	//Distancia en Y entre jugador y la siguiente colisión horizontal
	ray_data->y_intercept = floor(game->player->y / cell_height) * cell_height;
	//Si el rayo esta hacia abajo la colisión será en la siguiente casil la
	if (!ray_data->up)
		ray_data->y_intercept += cell_height;
	//Distancia en X entre jugador y la siguiente colision horizontal
	ray_data->adjacent = fabs((game->player->y - ray_data->y_intercept) / tan(ray_angle));
	//Distancia en Y entre dos casillas
	ray_data->y_step = cell_height;
	//Si el rayo va hacia arriba hay que restar las Y
	if (ray_data->up)
		ray_data->y_step *= -1;
	//Distancia en X entre dos colisiones horizontales
	ray_data->x_step = cell_width / tan(ray_angle);
	//Si el rayo va hacia la izquierda hay que restar las X
	if ((!ray_data->left && ray_data->x_step < 0) || (ray_data->left && ray_data->x_step > 0))
		ray_data->x_step *= -1;
	//Punto de X de la primera colisión linea horizontal
	ray_data->x_intercept = game->player->x + (game->player->y - ray_data->y_intercept) / tan(ray_angle);
	//Actualizo los valores de la primera colisión horizontal
	ray_data->next_horizontal_x = ray_data->x_intercept;
	ray_data->next_horizontal_y = ray_data->y_intercept;
	//Si miramos hacia arriba hay que comprobar la casilla anterior
	if (ray_data->up)
		ray_data->next_horizontal_y--;
	//printf("horizontal x_step %f, y_step: %f\n",ray_data->x_step, ray_data->y_step);
}

void	set_vertical_vars(t_game *game, t_ray *ray, double cell_height, double cell_width)
{
	(void)cell_height;
	double	ray_angle;

	//printf("player angle: %f\n", game->player->ray);
	ray_angle = game->player->ray;
	//Distancia en X entre jugador y la siguiente colisión vertical
	ray->x_intercept = floor(game->player->x / cell_width) * cell_width;
	//Si el rayo esta hacia la derecha la colisión será en la siguiente casil la
	if (!ray->left)
		ray->x_intercept += cell_width;
	//Distancia en Y entre jugador y la siguiente colision vertical
	ray->opposite = (game->player->x - ray->x_intercept) * tan(ray_angle);
	//Distancia en X entre dos casillas
	ray->x_step = cell_width;
	//Si el rayo va hacia la izquierda hay que restar las X
	if (ray->left)
		ray->x_step *= -1;
	//Distancia en Y entre dos colisiones verticales
	ray->y_step = cell_height * tan(ray_angle);
	
	//Si el rayo va hacia arriba hay que restar las Y
	if ((!ray->up && ray->y_step < 0) || (ray->up && ray->y_step > 0))
		ray->y_step *= -1;
	//Punto de Y de la primera colisión linea vertical
	ray->y_intercept = game ->player->y + ray->opposite;
	//Actualizo los valores de la primera colisión vertical
	ray->next_vertical_x = ray->x_intercept;
	ray->next_vertical_y = ray->y_intercept;
	//Si miramos hacia la izquierda hay que comprobar la casilla anterior
	if (ray->left)
		ray->next_vertical_x--;
	//printf("vertocal x_step %f, y_step: %f\n",ray->x_step, ray->y_step);
}

void	set_direction(t_game *game)
{
	//Si el rayo esta entre 0 y 180 grados
	if (game->player->ray > 0 && game->player->ray < M_PI)
		game->player->ray_data->up = 1;
	//Si el rayo esta entre 90 y 270 grados
	if (game->player->ray > M_PI_2 && game->player->ray < 3 * M_PI_2)
		game->player->ray_data->left = 1;
}

void reset_vars(t_ray *ray_data)
{
	ray_data->up = 0;
	ray_data->left = 0;
	ray_data->horizontal_hit = 0;
	ray_data->horizontal_x_hit = 0;
	ray_data->horizontal_y_hit = 0;
	ray_data->vertical_hit = 0;
	ray_data->vertical_x_hit = 0;
	ray_data->vertical_y_hit = 0;
	ray_data->horizontal_distance = 9999;
	ray_data->vertical_distance = 9999;
	ray_data->wall_hit_x = 0;
	ray_data->wall_hit_y = 0;
	ray_data->adjacent = 0;
	ray_data->opposite = 0;
}

void	draw_opposite(t_game *game, t_ray *ray_data)
{
	int	i;
	int	pixel_index;
	if (ray_data->left)
	{
		i = -1;
		while (i > ray_data->opposite)
		{
			pixel_index = (game->player->y * game->frame->line_bytes) + (game->player->x * (game->frame->bitsinpixel / 8)) - i;
        	*(int *)(game->frame->addr + pixel_index) = 0x00FFFF;
			i--;

		}
	}
	else
	{
		i = 1;
		while (i > ray_data->opposite)
		{
			pixel_index = (game->player->y * game->frame->line_bytes) + (game->player->x * (game->frame->bitsinpixel / 8)) + i;
			*(int *)(game->frame->addr + pixel_index) = 0x00FFFF;
			i++;
		}
	}
}

void draw_horizontal_line_dynamic(t_game *game, int x_start, int x_end, int y, int color)
{
    int x;

    // Asegurarse de que x_start y x_end estén dentro de los límites de la ventana
    x_start = fmin(game->width - 1, fmax(0, x_start));
    x_end = fmin(game->width - 1, fmax(0, x_end));

    // Determinar la dirección de dibujo
    int step = (x_start < x_end) ? 1 : -1;

    // Iniciar el bucle
    x = x_start + 31;
	y = y + 31;
	x_end = x_end + 31;
	
    while (x != x_end)
    {
        int pixel_index = (y * game->frame->line_bytes) + (x * (game->frame->bitsinpixel / 8));
        *(int *)(game->frame->addr + pixel_index) = color;
        x += step;
    }

    // Pintar el último píxel
    int last_pixel_index = (y * game->frame->line_bytes) + (x * (game->frame->bitsinpixel / 8));
    *(int *)(game->frame->addr + last_pixel_index) = color;
}

void	draw_vertical_lyne_dynamic(t_game *game, int y_start, int y_end, int x, int color)
{
    int y;

    // Asegurarse de que x_start y x_end estén dentro de los límites de la ventana
    y_start = fmin(game->height - 1, fmax(0, y_start));
    y_end = fmin(game->height - 1, fmax(0, y_end));

    // Determinar la dirección de dibujo
    int step = (y_start < y_end) ? 1 : -1;

    // Iniciar el bucle
    y = y_start + 31;
	x = x + 31;
	y_end = y_end + 31;
	
    while (y != y_end)
    {
        int pixel_index = (y * game->frame->line_bytes) + (x * (game->frame->bitsinpixel / 8));
        *(int *)(game->frame->addr + pixel_index) = color;
        y += step;
    }

    // Pintar el último píxel
    int last_pixel_index = (y * game->frame->line_bytes) + (x * (game->frame->bitsinpixel / 8));
    *(int *)(game->frame->addr + last_pixel_index) = color;
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	set_hit_point(t_game *game, t_ray *ray_data)
{
	if (ray_data->horizontal_hit)
		ray_data->horizontal_distance = distance(game->player->x, game->player->y, ray_data->horizontal_x_hit, ray_data->horizontal_y_hit);
	if (ray_data->vertical_hit)
		ray_data->vertical_distance = distance(game->player->x, game->player->y, ray_data->vertical_x_hit, ray_data->vertical_y_hit);
	if (ray_data->horizontal_distance < ray_data->vertical_distance)
	{
		ray_data->wall_hit_x = ray_data->horizontal_x_hit;
		ray_data->wall_hit_y = ray_data->horizontal_y_hit;
		ray_data->distance = ray_data->horizontal_distance;
		//printf(RED"horizontal x_hit %f y_hit %f\n"WHITE, ray_data->wall_hit_x, ray_data->wall_hit_y );
	}
	else
	{
		ray_data->wall_hit_x = ray_data->vertical_x_hit;
		ray_data->wall_hit_y = ray_data->vertical_y_hit;
		ray_data->distance = ray_data->vertical_distance;
		//printf(RED"vertical x_hit %f y_hit %f\n"WHITE, ray_data->wall_hit_x, ray_data->wall_hit_y );
	}
	
}

double	to_rad(double angle)
{
	return (angle * (M_PI / 180));
}

void	normalize_angle(double *angle)
{
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
	if (*angle < 0)
		*angle += 2 * M_PI;
}

void	w_for_rays(t_game *game, t_ray *ray_data, double cell_height, double cell_width)
{
	int		i;
	double	start_rad;
	double	rad_step;

	i = 0;
	start_rad = game->player->ray;
	game->player->ray -= to_rad(game->player->fov / 2);
	rad_step = to_rad(60.0 / NO_RAYS);
	printf("rad_step: %f\n", rad_step);
	printf(GREEN"w_for_rays"WHITE);
	while(i < NO_RAYS)
	{
		reset_vars(ray_data);
		set_direction(game);
		set_horizontal_vars(game, ray_data, cell_height, cell_width);	
		find_next_horizontal_hit(game, ray_data, cell_height, cell_width);
		set_vertical_vars(game, ray_data, cell_height, cell_width);
		find_next_vertical_hit(game, ray_data, cell_height, cell_width);
		set_hit_point(game, ray_data);
		draw_ray(game->player->x, game->player->y, ray_data->wall_hit_x, ray_data->wall_hit_y, game->frame);
		game->player->ray += rad_step;
		normalize_angle(&game->player->ray);
		i++;
	}
	game->player->ray = start_rad;
}

void init_ray_cast(t_game *game, double cell_height, double cell_width)
{
	int		do_while;
	t_ray	*ray_data;

	do_while = 1;
	ray_data = game->player->ray_data;
	if (do_while)
		w_for_rays(game, ray_data, cell_height, cell_width);
	else
	{	
		printf("ray: %f\n", game->player->ray);
		reset_vars(ray_data);
		set_direction(game);
		set_horizontal_vars(game, ray_data, cell_height, cell_width);	
		find_next_horizontal_hit(game, ray_data, cell_height, cell_width);
		set_vertical_vars(game, ray_data, cell_height, cell_width);
		find_next_vertical_hit(game, ray_data, cell_height, cell_width);
		set_hit_point(game, ray_data);
		draw_ray(game->player->x, game->player->y, ray_data->wall_hit_x, ray_data->wall_hit_y, game->frame);
		draw_horizontal_line_dynamic(game, game->player->x, ray_data->wall_hit_x, game->player->y, 0x00FF00);
		draw_vertical_lyne_dynamic(game, game->player->y, ray_data->wall_hit_y, ray_data->wall_hit_x, 0x0000FF);
	}
}