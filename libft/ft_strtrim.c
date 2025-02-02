/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:45:05 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 18:11:48 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	ft_checkcar(const char *set, const char car)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == car)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		start;	
	size_t		end;
	size_t		i;
	char		*ptr;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_checkcar(set, s1[start]))
		start++;
	while (end > start && ft_checkcar(set, s1[end - 1]))
		end--;
	ptr = malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	ptr[end - start] = 0;
	while (end > start)
		ptr[i++] = s1[start++];
	return (ptr);
}
/*
int	main(int ac, char **av)
{
	if (ac)
		printf("%s", ft_strtrim((const char *)av[1], (const char *)av[2]));
	return (0);
}*/
