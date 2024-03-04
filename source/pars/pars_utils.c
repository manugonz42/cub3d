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
	int		size;

	j = i;
	size = 0;
	while (line[j] && !ft_isspace(line[j]) && line[j] != '\n')
	{
		j++;
		size++;
	}
	word = ft_substr(line, i, size - i);
	if (next_token(line, j) != 0 && next_token(line, i) == '\n')
		ft_error_message(INVALID_LINE, game);
	return (word);
}

void	save_texture(char *line, t_game *game, int side, int i)
{
	if (side == NO && game->sprites.no->setted == 0)
	{
		game->sprites.no->addr = save_texture_path(line, i, game);
		game->sprites.no->setted = 1;
	}
	else if (side == SO && game->sprites.so->setted == 0)
	{
		game->sprites.so->addr = save_texture_path(line, i, game);
		game->sprites.so->setted = 1;
	}
	else if (side == EA && game->sprites.ea->setted == 0)
	{
		game->sprites.ea->addr = save_texture_path(line, i, game);
		game->sprites.ea->setted = 1;
	}
	else if (side == WE && game->sprites.we->setted == 0)
	{
		game->sprites.we->addr = save_texture_path(line, i, game);
		game->sprites.we->setted = 1;
	}
	else
		ft_error_message(REPIATED_ARG, game);
}
