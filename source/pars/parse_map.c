#include "cub3d.h"

void	parse_texture(char *line, t_game *game, int side)
{
	(void)side;
	int	i;

	i = 2;
	if (!ft_isspace(line[i]))
		ft_error_message(INVALID_LINE, game);
	ft_skip_spaces(&line);
	if (!line[i] || line[i] == '\n')
		ft_error_message(INVALID_LINE, game);
	save_texture(line, game, side, i);
}

int	parse_line(char *line, t_game *game)
{
	ft_skip_spaces(&line);
	if (line[0] == 'N' && line[1] == 'O')
		parse_texture(line, game, NO);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_texture(line, game, SO);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_texture(line, game, EA);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_texture(line, game, WE);
	else if (line[0] == 'F')
		parse_color(line, game, F);
	else if (line[0] == 'C')
		parse_color(line, game, C);
	else if (line[0] == '\0' || line[0] == '\n')
			return (1);
	else
			ft_error_message(INVALID_LINE, game);
	return (1);
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
	/*if (line[i] != '\n')
		ft_error_message(MISSING_NL, game);*/
}

void	parse_map_line(char *line, t_game *game)
{
	char	*temp;

	check_line_map_format(line, game);
	temp = ft_strjoin(game->map->raw_map, line);
	free(game->map->raw_map);
	game->map->raw_map = temp;
}

int	parse_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*cpy;
	int		in_map;

	in_map = 0;
	fd = open(game->map->cub_path, O_RDONLY);
	if (fd == -1)
		ft_error_message("Invalid map path", game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cpy = line;
		ft_skip_spaces(&cpy);
		if (cpy[0] == '1')
			in_map = 1;
		if (in_map)
			parse_map_line(line, game);
		else
			parse_line(cpy, game);
		free(line);
	}
	close(fd);
	return (1);
}