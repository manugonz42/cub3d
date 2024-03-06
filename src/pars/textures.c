#include "cub3d.h"

void    set_textures(t_game *game)
{
	game->sprites->no->addr = mlx_get_data_addr(game->sprites->no->ptr, &game->sprites->no->bitsinpixel, &game->sprites->no->line_bytes, &game->sprites->no->endian);
	game->sprites->so->addr = mlx_get_data_addr(game->sprites->so->ptr, &game->sprites->so->bitsinpixel, &game->sprites->so->line_bytes, &game->sprites->so->endian);
	game->sprites->ea->addr = mlx_get_data_addr(game->sprites->ea->ptr, &game->sprites->ea->bitsinpixel, &game->sprites->ea->line_bytes, &game->sprites->ea->endian);
	game->sprites->we->addr = mlx_get_data_addr(game->sprites->we->ptr, &game->sprites->we->bitsinpixel, &game->sprites->we->line_bytes, &game->sprites->we->endian);
}
