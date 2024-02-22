#include "cub3d.h"

void	destroy_game(t_game *game)
{
	mlx_destroy_window(game->mlx_server, game->mlx_window);
}

int		ft_closed(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}