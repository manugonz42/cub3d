#include "cub3d.h"

void create_background(t_game *game)
{
//	int sky_color;
//	int	floor_color;
	int back;

	back = game->sprites.c->rgb;
//	sky_color = game->sprites.c->rgb;
//	floor_color = game->sprites.f->rgb;
	game->frame = malloc(sizeof(t_image));
	game->frame->ptr = mlx_new_image(game->mlx_server, game->width, game->height);
	game->frame->addr = mlx_get_data_addr(game->frame->ptr, &game->frame->bitsinpixel, &game->frame->line_bytes, &game->frame->endian);
	for (int i = 0; i < game->width * game->height; i++)
	{
/*		if (i < game->width * game->height / 2)
			*(int *)(game->frame->addr + i * 4) = sky_color;
		else
			*(int *)(game->frame->addr + i * 4) = floor_color;
*/		*(int *)(game->frame->addr + i * 4) = back;
	}
}

void	create_map(t_game *game)
{
	int	wall_color;
	int	space_color;

	create_background(game);
	wall_color = game->sprites.b->rgb;
	space_color = game->sprites.w->rgb;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (game->map->matrix[i][j] == '1')
				for (int k = 0; k < 121; k++)
					for (int l = 0; l < 31; l++)
						*(int *)(game->frame->addr + (i * 32 + l) * game->frame->line_bytes + j * 128 + k) = wall_color;
			else
				for (int k = 0; k < 121; k++)
					for (int l = 0; l < 31; l++)
						*(int *)(game->frame->addr + (i * 32 + l) * game->frame->line_bytes + j * 128 + k) = space_color;
		}
	}
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
	mlx_destroy_image(game->mlx_server, game->frame->ptr);
}