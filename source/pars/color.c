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
		ft_error_message(INVALID_COLOR, game);
}

void	check_color_format(char *line, t_game *game)
{
	int	i;
	int	commas;

	i = 0;
	if (!line[1] || line[1] != ' ')
		ft_error_message(INVALID_LINE, game);
	line++;
	ft_skip_spaces(&line);
	if (!line[i] || line[i] == '\n')
		ft_error_message(INVALID_LINE, game);
	commas = 0;
	while(line[i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
			ft_error_message(INVALID_COLOR, game);
		if (line[i] == ',')
			comma_case(line, &i, &commas, game);
		i++;
	}
	if (commas != 2 || line[i] != '\n' || line[i - 1] == ',')
		ft_error_message(INVALID_COLOR, game);
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
			ft_error_message(INVALID_COLOR, game);
		i++;
	}
	res = create_trgb(0, ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	i = 0;
	while (i < 3)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (res);
}

void	parse_color(char *line, t_game *game, int side)
{
	check_color_format(line, game);
	line++;
	ft_skip_spaces(&line);
	if (side == F)
		game->sprites.f->rgb = extract_color(line, game);
	else
		game->sprites.c->rgb = extract_color(line, game);
}