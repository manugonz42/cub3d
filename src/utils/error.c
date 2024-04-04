/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:56:44 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 12:04:26 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *message, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd (message, 2);
	ft_putstr_fd ("\n", 2);
	if (game)
		free_program(game);
	exit(EXIT_FAILURE);
}
