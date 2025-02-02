/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:47:37 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 20:43:32 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*tmp;

	tmp = b;
	while (len--)
		tmp[len] = 0;
	return (b);
}
/*
int main ()
{
	char a[] = {1, 2, 3, 6};
	char *c;
	int i = 0;

	c = ft_bzero(a, 3);
	while(i < 3)
	{
		printf("%d", c[i++]);
	}
}*/
