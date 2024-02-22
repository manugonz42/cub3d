#include "libft.h"

void	ft_print_matrix(char **matrix)
{
	int i;

	i = 0;
	while(matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
