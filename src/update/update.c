#include "cub3d.h"

void	update_player_pos(t_game *game)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player->x;
	new_y = game->player->y;
	if (game->player->moving == 0)
		return ;
	if (game->player->moving == AHEAD)
	{
		new_x = game->player->x - game->player->mov_speed * cos(game->player->ray);
		new_y = game->player->y - game->player->mov_speed * sin(game->player->ray);
	}
	if (game->player->moving == BACK)
	{
		new_x = game->player->x + game->player->mov_speed * cos(game->player->ray);
		new_y = game->player->y + game->player->mov_speed * sin(game->player->ray);
	}
	if (game->player->moving == RIGHT)
	{
		new_x = game->player->x - game->player->mov_speed * cos(game->player->ray + M_PI_2);
		new_y = game->player->y - game->player->mov_speed * sin(game->player->ray + M_PI_2);
	}
	if (game->player->moving == LEFT)
	{
		new_x = game->player->x - game->player->mov_speed * cos(game->player->ray - M_PI_2);
		new_y = game->player->y - game->player->mov_speed * sin(game->player->ray - M_PI_2);
	}
	if (game->map->matrix[(int)new_y / TILE_SIZE][(int)new_x / TILE_SIZE] != '1')
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	update_ray(t_game *game)
{
	if (game->player->rotating == 0)
		return ;
	if (game->player->rotating == ROT_LEFT)
		game->player->ray -= game->player->rot_speed;
	if (game->player->rotating == ROT_RIGHT)
		game->player->ray += game->player->rot_speed;
	if (game->player->ray < 0)
		game->player->ray += 2 * M_PI;
	if (game->player->ray > 2 * M_PI)
		game->player->ray -= 2 * M_PI;
}

int	release_input(int keysym, t_game *game)
{
	if (keysym)
	if (keysym == W_KEY || keysym == S_KEY || \
		keysym == A_KEY || keysym == D_KEY)
		game->player->moving = 0;
	if (keysym == L_ARROW || keysym == R_ARROW)
		game->player->rotating = 0;
	return (0);
}

int	press_input(int keysym, t_game *game)
{
	if (keysym)
	if (keysym == ESC_KEY)
		free_program(game);
	if (keysym == W_KEY)
		game->player->moving = AHEAD;
	if (keysym == S_KEY)
		game->player->moving = BACK;
	if (keysym == D_KEY)
		game->player->moving = RIGHT;
	if (keysym == A_KEY)
		game->player->moving = LEFT;
	if (keysym == L_ARROW)
		game->player->rotating = ROT_LEFT;
	if (keysym == R_ARROW)
		game->player->rotating = ROT_RIGHT;
	return (0);
}
