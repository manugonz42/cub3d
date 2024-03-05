#include "cub3d.h"

int		check_first_or_last_row(char *line, t_game *game)
{
	int i;

	i = 0;
	ft_skip_spaces(&line);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_error_message(NOT_WALL_SR_MAP, game);
		i++;
	}
	return (1);
}

int		check_empty_map_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 10 && line[i + 1] == 10 && \
			next_token(line, i))
			return (1);
		i++;
	}
	return (0);
}

void	check_first_or_last_clmns(t_game *game)
{
	int i;

	i = 0;
	while(game->map->matrix[i])
	{
		if (next_token(game->map->matrix[i], 0) != '1')
			ft_error_message(NOT_WALL_SR_MAP, game);
		if (last_token(game->map->matrix[i], 0) != '1')
			ft_error_message(NOT_WALL_SR_MAP, game);
		i++;
	}
}

void	n_of_cols(t_game *game)
{
	int i;
	int j;
	int max;

	i = 0;
	game->map->cols = 0;
	max = 0;
	while(game->map->matrix[i])
	{
		j = 0;
		while(game->map->matrix[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	game->map->cols = max;
}

void	n_of_rows(t_game *game)
{
	int	i;

	i = 0;
	game->map->rows = 0;
	while (game->map->matrix[i])
	{
		game->map->rows++;
		i++;
	}
}