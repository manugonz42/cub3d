#include "cub3d.h"

void	check_adjacent_cells(int i, int j, t_game *game)
{
	if (game->map->matrix[i][j] == '0')
	{
		if (game->map->matrix[i][j - 1] == ' '  || !game->map->matrix[i][j - 1] \
			|| game->map->matrix[i][j + 1] == ' ' || !game->map->matrix[i][j + 1] \
			|| game->map->matrix[i - 1][j] == ' ' || !game->map->matrix[i - 1][j] \
			|| game->map->matrix[i + 1][j] == ' ' || !game->map->matrix[i + 1][j])
			ft_error_message(NOT_WALL_SR_MAP, game);
		/*printf("cell[%i][%i]: %c, cell[-1][0] %i, cell[0][-1] %i,\
		cell[0][+1] %i, cell[+1][0] %i\n",\
		i, j, \
		game->map->matrix[i][j], game->map->matrix[i][j - 1],\
		game->map->matrix[i][j + 1], game->map->matrix[i - 1][j],\
		game->map->matrix[i + 1][j]);*/
	}
}

void	check_wall_status(t_game *game)
{
	int	i;
	int	j;

	check_first_or_last_row(game->map->matrix[0], game);
	i = 1;
	n_of_rows(game);
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