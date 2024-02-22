#include "cub3d.h"

void draw_cell(t_game *game, char cell, int x, int y)
{
    int color;
    int width;
    int height;
    int map_x = x * 10;
    int map_y = y * 10;

    if (cell == '1')
        color = create_trgb(0, 255, 255, 255);
    else if (cell == ' ')
        color = create_trgb(100, 100, 100, 100);
    else if (cell == '0')
        color = create_trgb(0, 0, 0, 0);
    else if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
        color = create_trgb(0, 211, 111, 211);

    height = 0;
    while (height < 10)
    {
        width = 0;
        while (width < 10)
        {
            int pixel_index = ((map_y + height) * game->map->cols * 10 + (map_x + width)) * 4; 
            *(int *)(game->mini_map->addr + pixel_index) = color;  // Cast a int para asignar 4 bytes
            width++;
        }
        height++;
    }
}




void	fill_minimap(t_game *game)
{
	int x;
	int y;
	
	y = 0;
    ft_print_matrix(game->map->matrix);
	while (y < game->map->rows)
	{
		x = 0;
		while (game->map->matrix[y][x])
		{
			draw_cell(game, game->map->matrix[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	print_minimap(t_game *game)
{
	n_of_cols(game);
    printf("cols: %d\n", game->map->cols);
	game->mini_map = malloc(sizeof(t_image));
	game->mini_map->ptr = mlx_new_image(game->mlx_server, game->map->cols * 10, game->map->rows * 10);
	game->mini_map->addr = mlx_get_data_addr(game->mini_map->ptr, &game->mini_map->bitsinpixel, &game->mini_map->line_bytes, &game->mini_map->endian);
	fill_minimap(game);
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->mini_map->ptr, 30, 30);
}