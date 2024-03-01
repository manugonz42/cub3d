#include "cub3d.h"

void	draw_pj(t_game *game)
{
	t_image *img;
	int		i;

	i = 0;
	img = malloc(sizeof(t_image));
	img->ptr = mlx_new_image(game->mlx_server, TILE_SIZE / 4, TILE_SIZE / 4);
	img->addr = mlx_get_data_addr(img->ptr, &img->bitsinpixel, &img->line_bytes, &img->endian);
	while(i < (TILE_SIZE) / 4 * (TILE_SIZE / 4))
	{
		*(int *)(img->addr + i * 4) = create_trgb(0, 255, 0, 0);
		i++;
	}
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, img->ptr, game->player->x, game->player->y);
	mlx_destroy_image(game->mlx_server, img->ptr);
}

void	draw_colision(t_game *game, int x, int y)
{
	t_image *img;
	int		i;

	i = 0;
	img = malloc(sizeof(t_image));
	img->ptr = mlx_new_image(game->mlx_server, 3, 3);
	img->addr = mlx_get_data_addr(img->ptr, &img->bitsinpixel, &img->line_bytes, &img->endian);
	while(i < 9)
	{
		*(int *)(img->addr + i * 4) = create_trgb(0, 0, 255, 0);
		i++;
	}
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, img->ptr, x, y);
	mlx_destroy_image(game->mlx_server, img->ptr);
}