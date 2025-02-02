/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:07:40 by salmou            #+#    #+#             */
/*   Updated: 2024/11/07 20:08:47 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdio.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	int			i;
	char		*cdest;
	const char	*csrc;

	i = -1;
	cdest = (char *)dest;
	csrc = (const char *)src;
	if (src > dest)
		while (i++ < n - 1)
			cdest[i] = csrc[i];
	else if (src < dest)
		while (n--)
			cdest[n] = csrc[n];
	return (dest);
}
/*
int	main(int ac, char** av)
{
	char dest[] = "zzzzzzzzzz";
	int i = 0;

	printf("dest before is : %s\n", dest);
	ft_memmove(dest, av[1], av[2][0] - '0');
	printf("dest after is  : ");
	while(dest[i])
		printf("%c", dest[i++]);
	return (0);
}*/
