#include "cub3d.h"

void	print_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
}

void	cast_rays(t_game *game);

int		draw_next_frame(t_game *game)
{
	draw_background(game);
	draw_map(game);
	update_player_pos(game);
	update_ray(game);
	cast_rays(game);
	//create_pj(game);
	draw_pj(game);
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
	usleep(FPS_30);
	return (0);
}