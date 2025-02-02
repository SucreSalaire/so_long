/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:48:40 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 20:54:51 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, size_t c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return (tmp + i);
		i++;
	}
	return (0);
}
/*
#include "stdio.h"
int	main (int ac, char** av)
{
	int i = 0;
	char *result;
	result = ft_memchr(av[1], av[2][0], av[3][0] - '0');
	if (result)
		while (result[i])
			printf("%c", result[i++]);
	return (0);
}*/
