/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:44:00 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 21:17:55 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] != (char)c)
		return (0);
	//s = s + i;
	return ((char *)(s + i));
}
/*
#include "string.h"
#include "stdio.h"
int	main (int ac, char **av)
{
	printf("from string.h : %s\n", strrchr(av[1], av[2][0]));
	printf("from libft    : %s", ft_strrchr(av[1], av[2][0]));
	return (0);
}*/
