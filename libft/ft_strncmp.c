/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:41:29 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 00:31:50 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (!n)
		return (0);
	else if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include "stdio.h"
#include "string.h"
int main(char ac, char **av)
{
	printf("%i", ft_strncmp(av[1], av[2], av[3][0] - '0'));
	printf("%i", strncmp(av[1], av[2], av[3][0] - '0'));
}*/
