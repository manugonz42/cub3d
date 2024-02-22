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

int	ft_handle_input(int keysym, t_game *game)
{
	printf("key: %d\n", keysym);
	if (keysym == ESC_KEY)
		ft_closed(game);
	return (0);
}