/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:37:49 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:39:40 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_texture(char *line, t_game *game, int side)
{
	int	i;

	(void)side;
	i = 2;
	if (!ft_isspace(line[i]))
		err("MAP: invalid line format", game);
	ft_skip_spaces(&line);
	if (!line[i] || line[i] == '\n')
		err("MAP: invalid line format", game);
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
		err("MAP: invalid line format", game);
	return (1);
}

void	parse_map_line(char *line, t_game *game)
{
	char	*temp;

	check_line_map_format(line, game);
	temp = ft_strjoin(game->map->raw_map, line);
	free(game->map->raw_map);
	game->map->raw_map = temp;
}

void	add_walls_in_spcs(t_game *game)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	while (game->map->matrix[i])
	{
		k = 0;
		j = 0;
		while (game->map->matrix[i][j])
		{
			if (k == 0 && game->map->matrix[i][j] == '1')
				k = 1;
			if (k == 1 && game->map->matrix[i][j] == ' ')
				game->map->matrix[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	parse_input(t_game *game)
{
	int		fd;
	int		in_map;
	char	*line;

	in_map = 0;
	fd = open(game->map->path, O_RDONLY);
	if (fd == -1)
		err("1MAP: map not found", game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_nline(game, line, &in_map);
		free(line);
	}
	if (in_map == 0)
		err("2MAP: map not found", game);
	close(fd);
	create_new_map_matrix(game);
	check_wall_status(game);
	add_walls_in_spcs(game);
	return (1);
}
