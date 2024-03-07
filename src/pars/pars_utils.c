#include "cub3d.h"

int		is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	check_line_map_format(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_map_char(line[i]))
			ft_error_message(INVALID_MAP, game);
		i++;
	}
	/*if (last_token(line, 0) != '1')
		ft_error_message(INVALID_MAP, game);*/
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
