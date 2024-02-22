/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:21:53 by manugonz          #+#    #+#             */
/*   Updated: 2023/03/06 17:20:13 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	cont;
	int	neg;
	int	res;

	res = 0;
	cont = 0;
	while ((nptr[cont] > 8 && nptr[cont] < 14) || nptr[cont] == 32)
		cont++;
	if (nptr[cont] == 45)
		neg = -1;
	else
		neg = 1;
	if (nptr[cont] == '+' || nptr[cont] == '-')
		cont++;
	while (nptr[cont] >= '0' && nptr[cont] <= '9')
	{
		res = (res * 10) + (nptr[cont] - 48);
		cont++;
	}
	return (res * neg);
}
