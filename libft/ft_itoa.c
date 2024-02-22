/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:00 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/06 17:24:04 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	res;

	res = 0;
	if (n <= 0)
		res = 1;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	num;
	int		l;
	char	*str;

	num = (long)n;
	l = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = 0 + 48;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[l] = '\0';
	while (num)
	{
		str[--l] = 48 + num % 10;
		num /= 10;
	}
	return (str);
}
