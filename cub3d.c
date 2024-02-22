#include "cub3d.h"

void	run_game(t_game *game)
{
	mlx_key_hook(game->mlx_window, ft_handle_input, game);
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
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(EXIT_FAILURE);
	check_args(argc, argv, game);
	init_game(game);
	parse_map(game);
	create_new_map_matrix(game);
	check_wall_status(game);
	print_minimap(game);
	mlx_loop(game->mlx_server);
	return (0);
}
