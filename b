void	render_south(t_game *game, t_ray *ray, int n)
{
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;

	ty_off = 0;
	ty_step = 32 / ray->lineH;
	if (ray->lineH > game->height)
	{
		ty_off = (ray->lineH - game->height) / 2;
		ray->lineH = game->height;
	}
	ray->lineO = (game->height / 2) - (ray->lineH / 2);
	tx = (int)(ray->hx * 4) % 32;
	ty = ty_off * ty_step;
	for (int i = 0; i < ray->lineH; i++)
	{
		for (int j = 0; j < 4; j++)
			*(int *)(game->frame->addr + (i + (int)ray->lineO) * game->frame->line_bytes + n * 16 + 4 * j) = *(int *)(game->sprites->so->addr + ((int)ty * game->sprites->no->line_bytes) + (4 * (int)tx));
		ty += ty_step;
	}
}