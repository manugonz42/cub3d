#include "cub3d.h"

void	draw_colision(t_game *game, int x, int y);

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
	if ((!left && x_step > 0) || (left && x_step < 0))
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


float	ray_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	cast_rays(t_game *game)
{
	int mx, my, dof;
	float rx, ry, ra, xo, yo, aTan, nTan, dr, disH, disV, vx, vy, hx, hy;

	dr = M_PI / 180;
	ra = game->player->ray - 30 * dr;
	
	for (int r = 0; r < 60; r++)
	{
		//Colision con lineas horizontales
		dof = 0;
		disH = 10000000;
		aTan = -1 / tan(ra);
		if (ra < M_PI) //Angulo inferior a 180 grados (arriba)
		{
			//No entiendo muy bien la matemática aquí, pero como cada casilla en el mapa en el que estoy trabajando es de 32x32, calculamos
			//la distancia en el eje y (en el que nos movemos para estas colisiones) haciendo una aproximacion a la baja de 5 bits y luego
			//la distancia que se ha desplazado en el eje x con la inversa de la arcotangente del angulo (aTan)
			ry = (((int)game->player->y >> 5) << 5) - 0.0001;
			rx = (game->player->y - ry) * aTan + game->player->x;
			//apartir de ahí, el offset hasta la siguiente linea a evaluar va a ser siempre -32 apra el eje y, el offset para el eje x va a ser
			// -32 * aTan
			yo = - 32;
			xo = -yo * aTan;
		}
		else if (ra > M_PI) //Angulo superior a 180 grados (abajo)
		{
			//Igual que antes solo que como es hacia abajo, el redondeo es a la alza y el ofset de las 'y' es positivo
			ry = (((int)game->player->y >> 5) << 5) + 32;
			rx = (game->player->y - ry) * aTan + game->player->x;
			yo = 32;
			xo = -yo * aTan;
		}
		else if (ra == 0 || ra == M_PI) //Nunca hay colision horizontal porque es izquierda o derecha
		{
			rx = game->player->x;
			ry = game->player->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = ((int)(rx)>>5);
			my = ((int)(ry)>>5);
			if (mx < 0 || my < 0 || mx >= game->map->cols || my >= game->map->rows)
				dof = 8;
			else if (game->map->matrix[my][mx] == '1')
			{
				dof = 8;
				disH = ray_dist(game->player->x, game->player->y, rx, ry);
				hx = rx;
				hy = ry;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		//Vertical
		dof = 0;
		disV = 10000000;
		nTan = -tan(ra);
		if (ra < M_PI/2 || ra > 3 * M_PI/2)
		{
			rx = (((int)game->player->x >> 5) << 5) - 0.0001;
			ry = (game->player->x - rx) * nTan + game->player->y;
			xo = - 32;
			yo = -xo * nTan;
		}
		else if (ra > M_PI/2 && ra < 3 * M_PI/2)
		{
			rx = (((int)game->player->x >> 5) << 5) + 32;
			ry = (game->player->x - rx) * nTan + game->player->y;
			xo = 32;
			yo = -xo * nTan;
		}
		else if (ra == 0 || ra == M_PI)
		{
			rx = game->player->x;
			ry = game->player->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = ((int)(rx)>>5);
			my = ((int)(ry)>>5);
			if (mx < 0 || my < 0 || mx >= game->map->cols || my >= game->map->rows)
				dof = 8;
			else if (game->map->matrix[my][mx] == '1')
			{
				dof = 8;
				disV = ray_dist(game->player->x, game->player->y, rx, ry);
				vx = rx;
				vy = ry;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		//Renderizado
		if (disH < disV)
			draw_colision(game, (int)hx, (int)hy);
		else
			draw_colision(game, (int)vx, (int)vy);
		ra += dr;
	}
}
