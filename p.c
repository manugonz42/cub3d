#include "inc/cub3d.h"
int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
int main(void)
{
    t_game  game;
    t_image image;
    game.mlx_server = mlx_init();
    game.mlx_window = mlx_new_window(game.mlx_server, 500, 500, "prueba");
    image.ptr = mlx_new_image(game.mlx_server, 500, 500);
    image.addr = mlx_get_data_addr(image.ptr, &image.bitsinpixel, &image.line_bytes, &image.endian);
    int i = 0;
    printf("bitsinpixel%i line_bytes %i\n", image.bitsinpixel, image.line_bytes);
    while (i < 500 * 500 * 4)
    {
        *(int *)(image.addr + i) = create_trgb(0, 255, 0, 0);
        i += 4;
    }
    i = 0;
    int j = 0;
    while (j < 1)
    {
        while (i < 500)
        {
            *(int *)(image.addr + (i * image.bitsinpixel) + (j * image.line_bytes)) = create_trgb(0, 0, 0, 255);
            i += 4;
        }
        j++;
    }
    mlx_put_image_to_window(game.mlx_server, game.mlx_window, image.ptr, 0, 0);
    mlx_loop(game.mlx_server);
    return 0;
}