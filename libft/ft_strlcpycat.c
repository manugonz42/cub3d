#include "libft.h"

char	*ft_strlcpycat(char *s1, char *s2)
{
	char	*res;

	res = calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (res);
}