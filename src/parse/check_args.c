#include "cub3d.h"

char	next_t(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (line[i]);
	}
	return (0);
}

int all_args_setted(t_game *game)
{
	if (!game->sprites->c->setted || !game->sprites->f->setted
		|| !game->sprites->no->setted || !game->sprites->so->setted
		|| !game->sprites->we->setted || !game->sprites->ea->setted)
		return (0);
	return (1);
}