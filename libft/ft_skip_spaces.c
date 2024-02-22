#include "libft.h"

void	ft_skip_spaces(char **line)
{
	while (**line && (**line == ' ' || **line == 9 || (**line > 10 && **line <= 13)))
		(*line)++;
}