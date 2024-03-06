#include "cub3d.h"

int		is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	next_token(char *line, int i)
{
	while (line[i])
	{
		if (ft_isspace(line[i]) || line[i] == '\n')
			i++;
		else
			return (line[i]);
	}
	return (0);
}

int		last_token(char *line, int i)
{
	int last;

	last = i;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			last = line[i];
		i++;
	}
	return (last);
}

char	*save_texture_path(char *line, int i, t_game *game)
{
	char	*word;
	int		j;

	j = i + 1;
	while (line[j] && !ft_isspace(line[j]) && line[j] != '\n')
	{
		j++;
	}
	word = ft_substr(line, i + 1, j - i - 1);
	if (next_token(line, j) != 0 && next_token(line, i) == '\n')
		ft_error_message(INVALID_LINE, game);
	return (word);
}

void	save_texture(char *line, t_game *game, int side, int i)
{
	char	*path;

	path = save_texture_path(line, i, game);
	printf("path: %s\n", path);
	if (side == NO)
	{
		game->sprites->no->ptr = mlx_xpm_file_to_image(game->mlx_server,
			path, &game->sprites->no->width, &game->sprites->no->height);
		game->sprites->no->setted = 1;
	}
	else if (side == SO)
	{
		game->sprites->so->ptr = mlx_xpm_file_to_image(game->mlx_server,
			path, &game->sprites->so->width, &game->sprites->so->height);
		game->sprites->so->setted = 1;
	}
	else if (side == EA)
	{
		game->sprites->ea->ptr = mlx_xpm_file_to_image(game->mlx_server,
			path, &game->sprites->ea->width, &game->sprites->ea->height);
		game->sprites->ea->setted = 1;
	}
	else if (side == WE)
	{
		game->sprites->we->ptr = mlx_xpm_file_to_image(game->mlx_server,
			path, &game->sprites->we->width, &game->sprites->we->height);
		game->sprites->we->setted = 1;
	}
	else
	{
		free(path);
		ft_error_message(REPIATED_ARG, game);
	}
	free(path);
}
