#include "cub3d.h"

void create_background(t_game *game)
{
	int sky_color;
	int floor_color;

	floor_color = game->sprites.f->rgb;
	sky_color = game->sprites.c->rgb;
	game->frame = malloc(sizeof(t_image));
	game->frame->ptr = mlx_new_image(game->mlx_server, game->width, game->height);
	game->frame->addr = mlx_get_data_addr(game->frame->ptr, &game->frame->bitsinpixel, &game->frame->line_bytes, &game->frame->endian);
	for (int i = 0; i < game->width * game->height; i++)
	{
		if (i < game->width * game->height / 2)
			*(int *)(game->frame->addr + i * 4) = sky_color;
		else
			*(int *)(game->frame->addr + i * 4) = floor_color;
	}
}