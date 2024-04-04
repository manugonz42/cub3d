void	set_hcolision(t_game *game, t_ray *ray)
{
	int	dof;
	int	mx;
	int	my;

	dof = 0;
	while (dof < game->map->rows)
	{
		mx = ((int)(ray->x) >> TILE_BITS);
		my = ((int)(ray->y) >> TILE_BITS);
		if (mx < 0 || my < 0 || mx >= game->map->cols || my >= game->map->rows)
			dof = game->map->rows;
		else if (game->map->matrix[my][mx] == '1')
		{
			dof = game->map->rows;
			ray->disH = ray_dist(game->player->x, \
				game->player->y, ray->x, ray->y);
			ray->hx = ray->x;
			ray->hy = ray->y;
		}
		else
		{
			ray->x += ray->xo;
			ray->y += ray->yo;
			dof += 1;
		}
	}
}