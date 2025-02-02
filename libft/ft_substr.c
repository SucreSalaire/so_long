/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:47:03 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 17:52:51 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	if ((ft_strlen(s) - start < len))
		len = ft_strlen(s) - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	if (len > 0)
		while (len--)
			ptr[len] = s[start + len];
	return (ptr);
}
/*
int	main(int ac, char **av)
{
	printf("%s", ft_substr(av[1], av[2][0] - '0', av[3][0] - '0'));
	return (0);
}*/
