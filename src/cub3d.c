#include "cub3d.h"

void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx_server, draw_next_frame, game);
	mlx_hook(game->mlx_window, 17, 0, ft_closed, game);
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
	printf("Cubed\n");
	t_game	game;

	check_args(argc, argv, &game);
	printf("1\n");
	init_game(&game, argv[1]);
	printf("2\n");
	parse_map(&game);
	printf("3\n");
	create_new_map_matrix(&game);
	printf("4\n");
//	check_wall_status(&game);
	ft_print_matrix(game.map->matrix);
	printf("5\n");
//	create_map(&game);
	init_pj(&game);
	printf("6\n");
	set_textures(&game);
	printf("7\n");
//	draw_pj(&game);
	run_game(&game);
	while(1)
	{
		printf("Cubed\n");
		sleep(1);
	}
	return (0);
}
