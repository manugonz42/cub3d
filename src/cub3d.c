#include "cub3d.h"

void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx_server, draw_next_frame, game);
	mlx_loop(game->mlx_server);
}

void	check_args(int argc, char *argv[], t_game *game)
{
	int	len;

	if (argc < 2 || argc > 3)
		ft_error_message(INVALID_ARGS, NULL);
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(argv[1] + len - 4, ".cub", 4))
		ft_error_message(INVALID_FORMAT, game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_args(argc, argv, &game);
	init_game(&game, argv[1]);
	parse_map(&game);
	create_new_map_matrix(&game);
	check_wall_status(&game);
	ft_print_matrix(game.map->matrix);
//	create_map(&game);
	init_pj(&game);
//	draw_pj(&game);
	run_game(&game);
	return (0);
}
