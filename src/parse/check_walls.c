#include "cub3d.h"

void	check_adjacent_cells(int i, int j, t_game *game)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[i][j] == '0')
	{
		if (matrix[i][j - 1] == ' '  || !matrix[i][j - 1]
			|| matrix[i][j + 1] == ' ' || !matrix[i][j + 1]
			|| matrix[i - 1][j] == ' ' || !matrix[i - 1][j]
			|| matrix[i + 1][j] == ' ' || !matrix[i + 1][j])
			err("MAP: map must be surrounded by walls", game);
	}
}

void	check_wall_status(t_game *game)
{
	int	i;
	int	j;

	check_first_or_last_row(game->map->matrix[0], game);
	i = 1;
	while(i < game->map->rows - 1)
	{
		j = 0;
		while (game->map->matrix[i][j])
		{
			check_adjacent_cells(i, j, game);
			j++;
		}
		i++;
	}
	check_first_or_last_row(game->map->matrix[i], game);
}
