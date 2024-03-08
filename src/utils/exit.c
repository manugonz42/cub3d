#include "cub3d.h"

void	destroy_game(t_game *game)
{
	mlx_destroy_window(game->mlx_server, game->mlx_window);
}

void	destroy_images(t_game *game)
{
	if (game->sprites->no->setted)
		mlx_destroy_image(game->mlx_server, game->sprites->no->ptr);
	if (game->sprites->so->setted)
		mlx_destroy_image(game->mlx_server, game->sprites->so->ptr);
	if (game->sprites->we->setted)
		mlx_destroy_image(game->mlx_server, game->sprites->we->ptr);
	if (game->sprites->ea->setted)
		mlx_destroy_image(game->mlx_server, game->sprites->ea->ptr);
	if (game->sprites->f->setted)
		mlx_destroy_image(game->mlx_server, game->sprites->f->ptr);
	if (game->sprites->c->setted)
		mlx_destroy_image(game->mlx_server, game->sprites->c->ptr);
}

void	free_sprites(t_game *game)
{
	if (game->sprites->no)
		free(game->sprites->no);
	if (game->sprites->so)
		free(game->sprites->so);
	if (game->sprites->we)
		free(game->sprites->we);
	if (game->sprites->ea)
		free(game->sprites->ea);
	if (game->sprites->f)
		free(game->sprites->f);
	if (game->sprites->c)
		free(game->sprites->c);
	if (game->sprites)
		free(game->sprites);
}

void	free_map(t_game *game)
{
	if (game->map->raw_map)
		free(game->map->raw_map);
	if (game->map->matrix)
		ft_free_matrix(game->map->matrix);
	if (game->map)
		free(game->map);
}

void	free_frame(t_game *game)
{
	if (game->frame)
	{
		if (game->frame->ptr)
			mlx_destroy_image(game->mlx_server, game->frame->ptr);
		free(game->frame);
	}
}

void	free_all(t_game *game)
{
	destroy_images(game);
	free_sprites(game);
	free_map(game);
	free_frame(game);
	if (game->player)
		free(game->player);
	mlx_destroy_window(game->mlx_server, game->mlx_window);
}

int		ft_closed(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}
