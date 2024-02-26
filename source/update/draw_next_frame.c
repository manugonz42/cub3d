#include "cub3d.h"

void	print_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
}

int		draw_next_frame(t_game *game)
{
	//mlx_clear_window(game->mlx_server, game->mlx_window);
	printf("moving: %d, rotating: %d\n", game->player->moving, game->player->rotating);
	/*if (game->player->moving == 0 && game->player->rotating == 0)
		return (0);*/
	update_player_pos(game);
	update_ray(game);
	create_background(game);
	draw_minimap(game);
	init_ray_cast(game, 8, 8);
	print_frame(game);
	draw_pj(game);
	usleep(FPS_30);
	return (0);
}