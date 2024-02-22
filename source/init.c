#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->alloc = 0;
	game->mlx_server = mlx_init();
	if (!game->mlx_server)
	{
		free(game->mlx_server);
		ft_error_message("Mlx server start failed.\n", game);
	}
	game->mlx_window = mlx_new_window(game->mlx_server, 640, 480, "Cub3D");
	if (!game->mlx_window)
	{
		free (game->mlx_server);
		ft_error_message("Mlx window creation failed.\n", game);
	}
	mlx_key_hook(game->mlx_window, ft_handle_input, game);
}

void	init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_error_message(MALLOC_ERROR, game);
	game->map->cub_path = "map.cub";
	game->map->alloc = 0;
	game->map->rows = 0;
	game->map->cols = 0;
	game->map->matrix = NULL;
	game->map->raw_map = ft_strdup("");
}

void	init_sprites(t_game *game)
{
	game->sprites.no = malloc(sizeof(t_image));
	game->sprites.so = malloc(sizeof(t_image));
	game->sprites.ea = malloc(sizeof(t_image));
	game->sprites.we = malloc(sizeof(t_image));
	game->sprites.f = malloc(sizeof(t_image));
	game->sprites.c = malloc(sizeof(t_image));
	if (!game->sprites.no || !game->sprites.so || !game->sprites.ea || !game->sprites.we || !game->sprites.f || !game->sprites.c)
		ft_error_message(MALLOC_ERROR, game);
}

void	init_game(t_game *game)
{
	init_mlx(game);
	init_map(game);
	init_sprites(game);
	game->alloc = 1;
	game->c_count = 0;
}