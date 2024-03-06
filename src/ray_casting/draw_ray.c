#include "cub3d.h"
/*
void	draw_wall(int x, t_ray *ray_data, t_game *game)
{
    double  pixels_wall_size;
    double  pp_distance;
    int     wall_size;
    int     wall_bottom;
    int     wall_top;
    int     color;

    color = create_trgb(255, 125, 125, 125);
    pp_distance = TILE_SIZE / 2;
    pixels_wall_size = (TILE_SIZE / ray_data->distance) * pp_distance;
    wall_size = (int)pixels_wall_size;
    wall_top = (game->height / 2) - (wall_size / 2);
    wall_bottom = (game->height / 2) + (wall_size / 2);
    int y = wall_top;
	while (y != wall_bottom)
    {
        int pixel_index = (y * game->frame->line_bytes) + (x * (game->frame->bitsinpixel / 8));
        *(int *)(game->frame->addr + pixel_index) = color;
        y ++;
    }
    int last_pixel_index = (y * game->frame->line_bytes) + (x * (game->frame->bitsinpixel / 8));
    *(int *)(game->frame->addr + last_pixel_index) = color;
}

void draw_ray(int x, int y, int x2, int y2, t_image *image)
{
	printf("draw_ray: x: %d, y: %d, x2: %d, y2: %d\n", x, y, x2, y2);
    int color = create_trgb(0, 255, 0, 0);
    double delta_x = x2 - x;
    double delta_y = y2 - y;

    int pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    delta_x /= pixels;
    delta_y /= pixels;

    double pixel_x = x + 31;
    double pixel_y = y + 31;
    while(pixels)
    {
        *(int *)(image->addr + ((int)pixel_y * image->line_bytes + (int)pixel_x * (image->bitsinpixel / 8))) = color;
        pixel_x += delta_x;
        pixel_y += delta_y;
        pixels--;
		//printf("pixel_x: %f, pixel_y: %f\n", pixel_x, pixel_y);
    }
	printf("pixel_x: %f, pixel_y: %f\n", pixel_x, pixel_y);
}

*/