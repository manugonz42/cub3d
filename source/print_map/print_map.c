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
            *(int *)(game->minimap->img->addr + pixel_index) = color;  // Cast a int para asignar 4 bytes
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
    create_background(game);
	game->minimap->img->ptr = mlx_new_image(game->mlx_server, game->map->cols * 8, game->map->rows * 8);
	game->minimap->img->addr = mlx_get_data_addr(game->minimap->img->ptr, &game->minimap->img->bitsinpixel, &game->minimap->img->line_bytes, &game->minimap->img->endian);
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

    y = 0;
    while (y < game->minimap->height)
    {
    	x = 0;
        while (x < game->minimap->width)
        {
            int frame_x = x + 30;
            int frame_y = y + 30;

            if (frame_x < game->width && frame_y < game->height)
            {
                int frame_pixel_index = (frame_y * game->width + frame_x) * 4;
                int minimap_pixel_index = (y * game->minimap->width + x) * 4;
                *(int *)(game->frame->addr + frame_pixel_index) = *(int *)(game->minimap->img->addr + minimap_pixel_index);
            }
            x++;
        }
        y++;
    }
}
