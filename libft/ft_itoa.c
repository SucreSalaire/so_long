/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:18:55 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 18:03:39 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_log(int x, int base)
{
	int	i;

	i = 0;
	while (x)
	{
		x /= base;
		i++;
	}
	return (i);
}

static char	*ft_itoaplus(char *ptr, int len, int n, int i)
{
	if (i == 0)
		ptr = malloc(ft_log(len, 10) + 1);
	if (!ptr)
		return (NULL);
	while (len >= 1)
	{
		ptr[i++] = (n / len) % 10 + '0';
		len /= 10;
	}
	ptr[i] = 0;
	return (ptr);
}

static char	*ft_itoaminus(char *ptr, int len, int n)
{
	ptr = malloc(ft_log(len, 10) + 2);
	if (!ptr)
		return (NULL);
	ptr[0] = '-';
	ptr = ft_itoaplus(ptr, len, -n, 1);
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;

	len = 1;
	ptr = NULL;
	if (n == -2147483648)
	{
		ptr = ft_strdup("-2147483648");
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	while ((n / len) > 9 || (n / len) < -9)
		len *= 10;
	if (n < 0)
		ptr = ft_itoaminus(ptr, len, n);
	else
		ptr = ft_itoaplus(ptr, len, n, 0);
	if (!ptr)
		return (NULL);
	return (ptr);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(123456));
	printf("%s", ft_itoa(-456789));
	return (0);
}*/
