/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:56:24 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 00:22:05 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_atoi(const char *a)
{
	int	n;
	int	i;
	int	signe;

	i = 0;
	n = 0;
	signe = 1;
	while ((a[i] >= 9 && a[i] <= 13) || a[i] == 32)
		i++;
	if (a[i] == '-' || a[i] == '+')
		signe *= 44 - a[i++];
	while (a[i] >= '0' && a[i] <= '9')
	{
		n *= 10;
		n += (a[i++] - '0');
	}
	n *= signe;
	return (n);
}
/*
int	main(int ac, char **av)
{
	printf("%i", ft_atoi(av[1]));
}*/
