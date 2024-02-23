#include "cub3d.h"

void	ft_move(t_game *game, int nx, int ny)
{
	(void)game;
	(void)nx;
	(void)ny;
	/*int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.matrix[nx][ny] != '1')
	{
		game->map.player.x = nx;
		game->map.player.y = ny;
		ft_print_map (game);
	}*/
}

int	on_release_input(int keysym, t_game *game)
{
	if (keysym)
	printf("key: %d soltada\n", keysym);
	if (keysym == W_KEY || keysym == S_KEY || \
		keysym == A_KEY || keysym == D_KEY)
		game->player->moving = 0;
	if (keysym == L_ARROW || keysym == R_ARROW)
		game->player->rotating = 0;
	return (0);
}
int	on_press_input(int keysym, t_game *game)
{
	if (keysym == ESC_KEY)
		ft_closed(game);
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