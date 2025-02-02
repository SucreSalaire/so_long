/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:38:48 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 20:56:39 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = 0;
	while (i--)
		ptr[i] = s[i];
	return (ptr);
}
/*
#include "stdio.h"
int	main(int ac, char **av)
{
	printf("%i", ft_strdup(av[1])[1]);
	return (0);
}*/
