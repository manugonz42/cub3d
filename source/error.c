#include "cub3d.h"

int	ft_error_message(char *message, t_game *game)
{
	free (game);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd (message, 1);
	exit (EXIT_FAILURE);
	return (0);
}