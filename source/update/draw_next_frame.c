#include "cub3d.h"

void	print_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx_server, game->mlx_window, game->frame->ptr, 0, 0);
}

void	draw2_rad(t_game *game)
{
    char *float_str;
    
	float_str = (char *)malloc(10 * sizeof(char));
    snprintf(float_str, 10, "%.2f", game->player->ray);
    mlx_string_put(game->mlx_server, game->mlx_window, game->player->x + 25, game->player->y + 10, 0x000000, float_str);
	free(float_str);
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
	draw2_rad(game);
	usleep(FPS_30);
	return (0);
}