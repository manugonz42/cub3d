#include "cub3d.h"

void	print_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
}

void	cast_rays(t_game *game);

int		draw_next_frame(t_game *game)
{
	create_background(game);
	update_player_pos(game);
	update_ray(game);
	cast_rays(game);
	create_map(game);
	//create_pj(game);
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
	mlx_destroy_image(game->mlx_server, game->frame->ptr);
	free(game->frame);
	draw_pj(game);
	usleep(FPS_30);
	return (0);
}