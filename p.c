#include "inc/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	init_mlx(t_game *game)
{
	game->mlx_server = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_server, 800, 600, "Pruebiña");
	game->frame = malloc(sizeof(t_image));
}

void fill_image_with_trasparency(t_image *image, int color)
{
    int x;
    int y;

    y = 0;
    while (y < 400)
    {
        x = 0;
        while (x < 400)
        {
            int *pixel = (int *)(image->addr + (y * image->line_bytes + x * (image->bitsinpixel / 8)));
            
            // Obtén los componentes de color existentes
            int dest_r = (*pixel >> 16) & 0xFF;
            int dest_g = (*pixel >> 8) & 0xFF;
            int dest_b = *pixel & 0xFF;

            // Obtiene los componentes de color del nuevo color
            int src_r = (color >> 16) & 0xFF;
            int src_g = (color >> 8) & 0xFF;
            int src_b = color & 0xFF;

            // Obtiene el canal alfa
            int alpha = (color >> 24) & 0xFF;

            // Realiza la mezcla teniendo en cuenta la transparencia
            *pixel = ((dest_r * (255 - alpha) + src_r * alpha) / 255) << 16 |
                     ((dest_g * (255 - alpha) + src_g * alpha) / 255) << 8 |
                     (dest_b * (255 - alpha) + src_b * alpha) / 255;

            x++;
        }
        y++;
    }
}

int on_press_input(int keysym, t_game *game)
{
	static int x = 0;
	if (x == 255)
		x = 0;
	if (keysym == ESC_KEY)
		exit(0);

	return (0);
}

int main(int argc, char const *argv[])
{
	t_image back;
	int i = 0;
	t_game 	game;
	t_image sprite;
	int		width;
	int		height;

	init_mlx(&game);
	back.ptr = mlx_new_image(game.mlx_server, 32, 32);
	back.addr = mlx_get_data_addr(back.ptr, &back.bitsinpixel, &back.line_bytes, &back.endian);
	sprite.ptr = mlx_xpm_file_to_image(game.mlx_server, "coin.xpm", &width, &height);
	sprite.addr = mlx_get_data_addr(sprite.ptr, &sprite.bitsinpixel, &sprite.line_bytes, &sprite.endian);
	if (!sprite.ptr)
		printf("Error\n");
	while (i < 32 * 32 * 4)
	{
		*(int *)(back.addr + i) = *(int *)(sprite.addr + i);
		i++;
	}
	mlx_put_image_to_window(game.mlx_server, game.mlx_window, sprite.ptr, 0, 0);
	mlx_put_image_to_window(game.mlx_server, game.mlx_window, back.ptr, 100, 100);
	mlx_key_hook(game.mlx_window, on_press_input, &game);
	mlx_loop(game.mlx_server);

	return 0;
}


