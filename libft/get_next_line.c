/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:28:03 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/26 13:28:04 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extract_line(char *next)
{
	int		i;
	char	*res;

	i = 0;
	if (!next[i])
		return (NULL);
	while (next[i] != '\n' && next[i])
		i++;
	if (next[i] == '\n')
		res = ft_calloc(i + 2, sizeof(char));
	else
		res = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (next[i] != '\n' && next[i])
	{
		res[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*ft_save_rest(char *next)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (next[i] != '\n' && next[i])
		i++;
	if (!next[i])
		return (free(next), NULL);
	res = ft_calloc(ft_strlen(next) - i + 1, sizeof(char));
	if (!res)
		return (free(next), NULL);
	j = 0;
	i++;
	while (next[i])
	{
		res[j] = next[i];
		i++;
		j++;
	}
	return (free(next), res);
}

char	*ft_add(char *next, char *buff)
{
	char	*res;

	res = ft_strjoin(next, buff);
	free (next);
	return (res);
}

char	*ft_read_l(int fd, char *next)
{
	int		s_read;
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (free(next), NULL);
	while (1)
	{
		s_read = read(fd, buff, BUFFER_SIZE);
		if (s_read == -1)
			return (free(buff), free(next), NULL);
		buff[s_read] = 0;
		if (s_read != 0)
			next = ft_add(next, buff);
		if (ft_strchr(buff, '\n') || s_read == 0 || !next)
			return (free(buff), next);
	}
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*line;

	if (!next)
		next = ft_calloc(1, 1);
	if (!next)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (free(next), next = NULL, NULL);
	next = ft_read_l(fd, next);
	if (next)
	{
		line = ft_extract_line(next);
		next = ft_save_rest(next);
		if (line)
			return (line);
	}
	return (free(next), next = NULL, NULL);
}
/*
int	main(void)
{
	char	*line;
	int		fda;

	int		i = 0;

	
	fda = open("map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fda);
		if(line == NULL)
			break;
		printf("%s\n", line);
	}
	
	free(line);
	close(fda);
	
	return (0);
}*/
