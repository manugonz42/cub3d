#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	comma_case(char *line, int *i, int *commas, t_game *game)
{
	if (line[*i] == ',')
		(*commas)++;
	if (*commas > 2)
		err("COLOUR: invalid colour", game);
}

void	check_color_format(char *line, t_game *game)
{
	int	i;
	int	commas;

	i = 0;
	if (!line[1] || line[1] != ' ')
		err("MAP: invalid line format", game);
	line++;
	ft_skip_spaces(&line);
	if (!line[i] || line[i] == '\n')
		err("MAP: invalid line format", game);
	commas = 0;
	while(line[i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
		{
			if (ft_isspace(line[i]) && next_t(line, i) == '\n')
				break ;
			err("COLOUR: invalid colour", game);
		}
		if (line[i] == ',')
			comma_case(line, &i, &commas, game);
		i++;
	}
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (commas != 2 || line[i] != '\n' || line[i - 1] == ',')
		err("2COLOUR: invalid colour", game);
}

int	extract_color(char *line, t_game *game)
{
	char	**temp;
	int		i;
	int		res;

	temp = ft_split(line, ',');
	i = 0;
	while (temp[i])
	{
		if (ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
			err("COLOUR: invalid colour", game);
		i++;
	}
	res = create_trgb(0, ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	ft_free_matrix(temp);
	return (res);
}

void	parse_color(char *line, t_game *game, int side)
{
	check_color_format(line, game);
	line++;
	ft_skip_spaces(&line);
	if (side == F)
	{
		if (game->sprites->f->setted)
			err("COLOUR: duplicate floor colour", game);
		game->sprites->f->rgb = extract_color(line, game);
		game->sprites->f->setted = 1;
	}
	else
	{
		if (game->sprites->c->setted)
			err("COLOUR: duplicate ceiling colour", game);
		game->sprites->c->rgb = extract_color(line, game);
		game->sprites->c->setted = 1;
	}
}