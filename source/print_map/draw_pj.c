#include "cub3d.h"

void	draw_pj(t_game *game)
{
	t_image *img;
	int		i;

	i = 0;
	img = malloc(sizeof(t_image));
	img->ptr = mlx_new_image(game->mlx_server, 3, 3);
	img->addr = mlx_get_data_addr(img->ptr, &img->bitsinpixel, &img->line_bytes, &img->endian);
	while(i < 9)
	{
		img->addr[i] = create_trgb(0, 255, 0, 0);
		i++;
	}
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, img->ptr, game->player->x + 30, game->player->y + 30);
}