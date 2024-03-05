#include "cub3d.h"

void	set_starting_pj_direction(t_game *game, char c)
{
	if (c == 'N')
		game->player->ray = M_PI_2;
	if (c == 'S')
		game->player->ray = 3 * M_PI_2;
	if (c == 'E')
		game->player->ray = 2 * M_PI;
	if (c == 'W')
		game->player->ray = M_PI;
}

void	set_starting_pj_pos(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map->matrix;
	y = 0;
	while(map[y])
	{
		if (ft_strchr(map[y], 'N') || ft_strchr(map[y], 'W') || \
		ft_strchr(map[y], 'E') || ft_strchr(map[y], 'S'))
		{
			x = 0;
			while(map[y][x] != 'N' && map[y][x] != 'S' && \
			map[y][x] != 'E' && map[y][x] != 'W')
				x++;
			break ;
		}
		y++;
	}
	game->player->fov = FOV;
	game->player->x = x * TILE_SIZE + TILE_SIZE / 2;
	game->player->y = y * TILE_SIZE + TILE_SIZE / 2;
	set_starting_pj_direction(game, map[y][x]);
}

void	init_pj(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_error_message(MALLOC_ERROR, game);
	game->player->fov = FOV;
	game->player->ray = 0;
	game->player->x = 0;
	game->player->y = 0;
	game->player->moving = 0;
	game->player->rotating = 0;
	game->player->mv_speed = 1;
	game->player->rot_speed = 6 * DR;
	set_starting_pj_pos(game);
}