#include "cub3d.h"

void create_background(t_game *game)
{
	int	i;

	sky_color = game->sprites.c->rgb;
	floor_color = game->sprites.f->rgb;
//	if (game->frame)
		//Liberacion de frame
//		free(game->frame);
	i = 0;
	game->frame = malloc(sizeof(t_image));
	if (!game->frame)
		ft_error_message(MALLOC_ERROR, game);
	game->frame->ptr = mlx_new_image(game->mlx_server, game->width, game->height);
	game->frame->addr = mlx_get_data_addr(game->frame->ptr, &game->frame->bitsinpixel, &game->frame->line_bytes, &game->frame->endian);
	while (i < game->width * game->height)
	{
		if (i < game->width * game->height / 2)
			*(int *)(game->frame->addr + i * 4) = game->sprites.c->rgb;
		else
			*(int *)(game->frame->addr + i * 4) = game->sprites.f->rgb;
		i++;
	}
}

void	create_map(t_game *game)
{
	for (int i = 0; i < game->map->rows; i++)
	{
		for (int j = 0; j < game->map->cols; j++)
		{
			if (game->map->matrix[i][j] && game->map->matrix[i][j] == '1')
				for (int k = 0; k < 4 * TILE_SIZE + 1; k++)
					for (int l = 0; l < TILE_SIZE; l++)
						*(int *)(game->frame->addr + (i * TILE_SIZE + l) * game->frame->line_bytes + j * 4 * TILE_SIZE + k) = create_trgb(0, 0, 0, 0);
			else if (game->map->matrix[i][j] && !ft_isspace(game->map->matrix[i][j]))
				for (int k = 0; k < 4 * TILE_SIZE + 1; k++)
					for (int l = 0; l < TILE_SIZE; l++)
						*(int *)(game->frame->addr + (i * TILE_SIZE + l) * game->frame->line_bytes + j * 4 * TILE_SIZE + k) = create_trgb(0, 255, 255, 255);
		}
	}
}
