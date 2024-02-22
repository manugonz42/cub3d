#include "include/libft.h"

char *add_spcs(char *s)
{
	printf("s: %s\n", s);
}

int	main(int argc, char *argv[])
{
	char *s = malloc(10);
	char *c = s;
	int i = 0;
	while(i < 9)
	{
		s[i] = 'b';
		i++;
	}
	s[i] = '\0';

	c = add_spcs(s);

	return (0);
}