/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:38:00 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 20:01:00 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		while (s[i] != (char)c)
			i++;
	else
		while (s[i] != (char)c && s[i])
			i++;
	if (s[i] == 0 && (char)c != 0)
		return (NULL);
	s = s + i;
	return ((char *)s);
}
/*
#include "stdio.h"
int main (int ac, char **av)
{
   char *ret;
   char *ret2;
   ret = strchr(av[1], (int)av[2][0]);
   ret2 = ft_strchr(av[1], (int)av[2][0]);
   printf("String after |%c| is - |%s|\n", av[2][0], ret);
   printf("String after |%c| is - |%s|\n", av[2][0], ret2);
   return(0);
}*/
