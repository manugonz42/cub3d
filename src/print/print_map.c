#include "cub3d.h"

void draw_cell(t_game *game, char cell, int x, int y)
{
    int color;
    int width;
    int height;
    int map_x = x * 8;
    int map_y = y * 8;

    if (cell == '1')
        color = create_trgb(0, 255, 255, 255);
    else if (cell == '0' || cell == 'N' || cell == 'S' || \
        cell == 'E' || cell == 'W')
        color = create_trgb(0, 200, 200, 200);
    else
        color = *(int *)(game->frame->addr + (map_y * game->map->cols * 8 + map_x) * 4);

    height = 0;
    while (height < 8)
    {
        width = 0;
        while (width < 8)
        {
            int pixel_index = ((map_y + height) * game->map->cols * 8 + (map_x + width)) * 4; 
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
//    ft_print_matrix(game->map->matrix);
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
            if (game->map->matrix[y][x])
			    draw_cell(game, game->map->matrix[y][x], x, y);
            else
                draw_cell(game, ' ', x, y);
			x++;
		}
		y++;
	}
}

void	save_minimap(t_game *game)
{
	n_of_cols(game);
 //   create_background(game);
	game->mini_map = malloc(sizeof(t_image));
	game->mini_map->ptr = mlx_new_image(game->mlx_server, game->map->cols * 8, game->map->rows * 8);
	game->mini_map->addr = mlx_get_data_addr(game->mini_map->ptr, &game->mini_map->bitsinpixel, &game->mini_map->line_bytes, &game->mini_map->endian);
	fill_minimap(game);
}

int get_img_width(t_image *img)
{
    return ((img->line_bytes * 8) / img->bitsinpixel);
}

int get_img_height(t_image *img)
{
    return img->line_bytes / img->bitsinpixel;
}

void draw_minimap(t_game *game)
{
	int	y;
	int	x;
    int frame_width = game->width;
    int frame_height = game->height;
	int minimap_width = game->map->cols * 8;
    int minimap_height = game->map->rows * 8;

    y = 0;
    while (y < minimap_height)
    {
    	x = 0;
        while (x < minimap_width)
        {
            int frame_x = x + 30;
            int frame_y = y + 30;

            if (frame_x < frame_width && frame_y < frame_height)
            {
                int frame_pixel_index = (frame_y * frame_width + frame_x) * 4;
                int minimap_pixel_index = (y * minimap_width + x) * 4;
                *(int *)(game->frame->addr + frame_pixel_index) = *(int *)(game->mini_map->addr + minimap_pixel_index);
            }
            x++;
        }
        y++;
    }
}
