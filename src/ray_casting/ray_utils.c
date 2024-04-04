/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:52:00 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 13:52:06 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	rdst(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	adjust_angle(float ra)
{
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;
	if (ra < 0)
		ra += 2 * M_PI;
	return (ra);
}
