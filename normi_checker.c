int	check_nline(t_game *game, int fd, int in_map)
{
	char	*line;
	char	*cpy;

	line = get_next_line(fd);
	if (!line)
		return (0);
	cpy = line;
	ft_skip_spaces(&cpy);
	if (cpy[0] == '1')
		in_map = 1;
	if (in_map)
		parse_map_line(line, game);
	else
		parse_line(cpy, game);
	free(line);
	return (1);
}

int	parse_map(t_game *game)
{
	int		fd;
	int		in_map;

	in_map = 0;
	fd = open(game->map->cub_path, O_RDONLY);
	if (fd == -1)
		ft_error_message("Invalid scene description file path", game);
	while (1)
	{
		if (!check_line_map_format(game, fd, in_map))
			break ;
	}
	if (in_map == 0)
		ft_error_message(NO_MAP, game);
	close(fd);
	return (1);
}
