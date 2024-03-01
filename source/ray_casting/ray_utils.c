#include "cub3d.h"

float	ray_dist(float ax, float ay, float bx, float by)
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
