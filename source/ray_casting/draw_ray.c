#include "cub3d.h"

void	draw_wall(int x, t_ray *ray_data, t_game *game)
{
	//double distance;

	//distance = (ray_data->distance / 8) * 720;
	printf("draw_wall: x: %d\n", x);
    int		pp_distance = game->width / 2 / tan(to_rad(game->player->fov) / 2);
	printf("pp_distance: %d\n", pp_distance);
	printf("1\n");
	int		wall_height = (game->height / ray_data->distance) * pp_distance;
	printf("distance %f\n", ray_data->distance);
	int		wall_top = (game->height / 2) - (wall_height / 2);
	printf("wall_top %i, wall_height %i, game_width %i\n", wall_top, wall_height, game->width);
	int		wall_bottom = (game->height / 2) + (wall_height / 2);
	printf("4\n");
	int		color = create_trgb(0, 125, 125, 125);
	int		y = wall_top;
	printf("5\n");
	while (y != wall_bottom)
    {
		printf("y: %d\n", y);
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

