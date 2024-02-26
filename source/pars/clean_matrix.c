#include "cub3d.h"

void fill_new_str(char *new_str, char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while(str[i])
	{
		if (k == 0 && str[i] != ' ' && str[i] != '\t')
			k = 1;
		if (str[i] == '\t')
		{
			add_spcs(new_str, j);
			j += 3;
		}
		else
			new_str[j] = str[i];
		if (k == 1 && str[i] == ' ')
			new_str[j] = '1';
		i++;
		j++;
	}
}

void	fill_new_matrix(char **matrix, char **new_matrix)
{
	int i;

	i = 0;
	while(matrix[i])
	{
		fill_new_str(new_matrix[i], matrix[i]);
		i++;
	}
	new_matrix[i] = NULL;
}

char	**tabs_to_spcs(t_game *game)
{
	char	**matrix;
	char	**new_matrix;

	matrix = ft_split(game->map->raw_map, '\n');
	new_matrix = realloc_to_tabs(matrix);
	fill_new_matrix(matrix, new_matrix);
	ft_free_matrix(matrix);
	return (new_matrix);
}

void	create_new_map_matrix(t_game *game)
{
	if (check_empty_map_line(game->map->raw_map))
		ft_error_message(EMPTY_LINE, game);
	game->map->matrix = tabs_to_spcs(game);
	n_of_rows(game);
	n_of_cols(game);
	//ft_print_matrix(game->map->matrix);
}