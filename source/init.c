#include "cub3d.h"

void	init_ray(t_game *game)
{
	game->player->ray_data->horizontal_hit = 0;
	game->player->ray_data->horizontal_x_hit = 0;
	game->player->ray_data->horizontal_y_hit = 0;
	game->player->ray_data->horizontal_distance = 9999;
	game->player->ray_data->vertical_hit = 0;
	game->player->ray_data->vertical_x_hit = 0;
	game->player->ray_data->vertical_y_hit = 0;
	game->player->ray_data->vertical_distance = 9999;
	game->player->ray_data->up = 0;
	game->player->ray_data->left = 0;
	game->player->ray_data->y_intercept = 0;
	game->player->ray_data->x_intercept = 0;
	game->player->ray_data->y_step = 0;
	game->player->ray_data->x_step = 0;
	game->player->ray_data->next_horizontal_x = 0;
	game->player->ray_data->next_horizontal_y = 0;
	game->player->ray_data->adjacent = 0;
	game->player->ray_data->opposite = 0;
}

void	init_mlx(t_game *game)
{
	game->alloc = 0;
	game->mlx_server = mlx_init();
	if (!game->mlx_server)
	{
		free(game->mlx_server);
		ft_error_message("Mlx server start failed.\n", game);
	}
	game->mlx_window = mlx_new_window(game->mlx_server, game->width, game->height, "Cub3D");
	if (!game->mlx_window)
	{
		free (game->mlx_server);
		ft_error_message("Mlx window creation failed.\n", game);
	}
	mlx_hook(game->mlx_window, 17, 0, ft_closed, game);
	mlx_hook(game->mlx_window, 2, 1L << 0, on_press_input, game);
	mlx_hook(game->mlx_window, 3, 1L << 1, on_release_input, game);
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

void	set_cell_dimensions(t_game *game)
{
	game->map->cell_height = (double)game->height / (double)game->map->rows;
	game->map->cell_width = (double)game->width / (double)game->map->cols;
	printf("game->height: %d, game->width: %d\n", game->height, game->width);
	printf("cell_height: %f, cell_width: %f\n", game->map->cell_height, game->map->cell_width);
}

void	init_minimap(t_game *game)
{
	game->minimap = malloc(sizeof(t_minimap));
	if (!game->minimap)
		ft_error_message(MALLOC_ERROR, game);
	game->minimap->img = malloc(sizeof(t_image));
	if (!game->minimap->img)
		ft_error_message(MALLOC_ERROR, game);
	game->minimap->width = 8 * game->map->cols;
	game->minimap->height = 8 * game->map->rows;
	game->minimap->cell_size = 8;
}

void	init_game(t_game *game)
{
	game->alloc = 1;
	game->c_count = 0;
	game->width = GAME_WIDTH;
	game->height = GAME_HEIGHT;
	init_mlx(game);
	init_map(game);
	init_sprites(game);
	parse_map(game);
	create_new_map_matrix(game);
	check_wall_status(game);
	init_minimap(game);
	set_cell_dimensions(game);
	init_pj(game);
	init_ray(game);
}