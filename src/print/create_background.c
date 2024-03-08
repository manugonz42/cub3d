#include "cub3d.h"

void	draw_background(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width * game->height)
	{
		if (i < game->width * game->height / 2)
			*(int *)(game->frame->addr + i * 4) = game->sprites->c->rgb;
		else
			*(int *)(game->frame->addr + i * 4) = game->sprites->f->rgb;
		i++;
	}
}

void	minimap_wall_case(t_game *game, int i, int j)
{
	int	l;
	int	k;

    k = 0;
    while (k < 4 * TILE_SIZE + 1)
    {
        l = 0;
        while (l < TILE_SIZE)
        {
            *(int *)(game->frame->addr + ((i + 1) * TILE_SIZE + l) * game->frame->line_bytes + \
				j * 4 * TILE_SIZE + k + 31) = create_trgb(0, 0, 0, 0);
            l++;
         }
        k++;
   	}
}

void	minimap_empty_case(t_game *game, int i, int j)
{
	int	l;
	int	k;

	k = 0;
	while (k < 4 * TILE_SIZE + 1)
	{
		l = 0;
		while (l < TILE_SIZE)
		{
			*(int *)(game->frame->addr + ((i + 1) * TILE_SIZE + l) * game->frame->line_bytes + \
				j * 4 * TILE_SIZE + k + 31) = create_trgb(0, 255, 255, 255);
			l++;
		}
		k++;
	}
}

void	draw_map(t_game *game)
{
    int i = 0;
    int j;

    while (i < game->map->rows)
    {
        j = 0;
        while (j < game->map->cols)
        {
            if (game->map->matrix[i][j] && game->map->matrix[i][j] == '1')
				minimap_wall_case(game, i, j);
            else if (game->map->matrix[i][j] && !ft_isspace(game->map->matrix[i][j]))
				minimap_empty_case(game, i, j);
            j++;
        }
        i++;
    }
}

