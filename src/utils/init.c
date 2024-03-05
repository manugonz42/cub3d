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

void	init_map(t_game *game, char *map)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_error_message(MALLOC_ERROR, game);
	game->map->cub_path = map;
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
	game->sprites.b = malloc(sizeof(t_image));
	game->sprites.w = malloc(sizeof(t_image));
	if (!game->sprites.no || !game->sprites.so || !game->sprites.ea || \
		!game->sprites.we || !game->sprites.f || !game->sprites.c)
		ft_error_message(MALLOC_ERROR, game);
	game->sprites.no->setted = 0;
	game->sprites.so->setted = 0;
	game->sprites.we->setted = 0;
	game->sprites.ea->setted = 0;
	game->sprites.f->setted = 0;
	game->sprites.c->setted = 0;
	game->sprites.b->setted = 0;
	game->sprites.w->setted = 0;
}

void	init_frame(t_game *game)
{
	game->frame = malloc(sizeof(t_image));
	if (!game->frame)
		ft_error_message(MALLOC_ERROR, game);
	game->frame->ptr = mlx_new_image(game->mlx_server, game->width, game->height);
	if (!game->frame->ptr)
		ft_error_message(MLX_ERROR, game);
	game->frame->addr = mlx_get_data_addr(game->frame->ptr, &game->frame->bitsinpixel, &game->frame->line_bytes, &game->frame->endian);

}

void	init_game(t_game *game, char *map)
{
	game->alloc = 1;
	game->c_count = 0;
	game->width = GAME_WIDTH;
	game->height = GAME_HEIGHT;
	init_mlx(game);
	init_map(game, map);
	init_sprites(game);
	init_frame(game);
}