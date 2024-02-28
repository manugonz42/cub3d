#include "cub3d.h"

int	ft_error_message(char *message, t_game *game)
{
	(void)game;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd (message, 2);
	ft_putstr_fd ("\n", 2);
	exit (EXIT_FAILURE);
	return (0);
}