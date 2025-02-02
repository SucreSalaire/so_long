/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:08 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 20:55:47 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while (i < n)
	{
		if (sc1[i] - sc2[i] != 0)
			return (sc1[i] - sc2[i]);
		i++;
	}
	return (0);
}
/*
#include "string.h"
#include "stdio.h"
int	main(int ac, char **av)
{
	printf("from string.h : %i\n", memcmp(av[1], av[2], av[3][0] - '0'));
	printf("from libft    : %i\n", ft_memcmp(av[1], av[2], av[3][0] -'0'));
	return (0);
}*/
