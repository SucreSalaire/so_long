/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:40:14 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 00:12:16 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	i = ft_strlen(src);
	return (i);
}
/*
#include "stdio.h"
#include "string.h"
int	main (int ac, char** av)
{
	char dst[10];
	//char dst2[10];
	char siz1 = ft_strlcpy(dst, av[1], 10);
	//char siz2 = strncpy(dst2, av[1], 10);
	printf("dst is %s of length %i", dst, siz1);
	printf("%c", dst[4]);
	printf("%c", dst[5]);
	printf("%c", dst[6]);
	printf("%c", dst[7]);
	printf("%c", dst[8]);
	printf("%c", dst[9]);
	//printf("dst is %s of length %i", dst2, siz1);
}*/
