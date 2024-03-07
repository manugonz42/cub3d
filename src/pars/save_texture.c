#include "cub3d.h"

void	no_case(t_game *game, char *path)
{
	game->sprites->no->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->no->width, &game->sprites->no->height);
	if (game->sprites->no->ptr == NULL)
		ft_error_message(INVALID_TEXTURE, game);
	game->sprites->no->setted = 1;
}

void	so_case(t_game *game, char *path)
{
	game->sprites->so->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->so->width, &game->sprites->so->height);
	if (game->sprites->so->ptr == NULL)
		ft_error_message(INVALID_TEXTURE, game);
	game->sprites->so->setted = 1;
}

void	we_case(t_game *game, char *path)
{
	game->sprites->we->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->we->width, &game->sprites->we->height);
	if (game->sprites->we->ptr == NULL)
		ft_error_message(INVALID_TEXTURE, game);
	game->sprites->we->setted = 1;
}

void	ea_case(t_game *game, char *path)
{
	game->sprites->ea->ptr = mlx_xpm_file_to_image(game->mlx_server,
		path, &game->sprites->ea->width, &game->sprites->ea->height);
	if (game->sprites->ea->ptr == NULL)
		ft_error_message(INVALID_TEXTURE, game);
	game->sprites->ea->setted = 1;
}

void	save_texture(char *line, t_game *game, int side, int i)
{
	char	*path;

	path = save_texture_path(line, i, game);
	if (side == NO)
		no_case(game, path);
	else if (side == SO)
		so_case(game, path);
	else if (side == EA)
		ea_case(game, path);
	else if (side == WE)
		we_case(game, path);
	else
	{
		free(path);
		ft_error_message(REPIATED_ARG, game);
	}
	free(path);
}
