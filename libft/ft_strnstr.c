/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:51:01 by salmou            #+#    #+#             */
/*   Updated: 2024/11/12 18:07:46 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_search	initzero_search(void)
{
	t_search	t;

	t.i = 0;
	t.j = 0;
	t.mem = 0;
	return (t);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	t_search	t;

	t = initzero_search();
	if (!little[0])
		return ((char *)big);
	while (big[t.i] && t.j < ft_strlen(little) && little[t.j] && t.i <= len)
	{
		if (big[t.i] == little[t.j])
		{
			if (t.j++ == 0)
				t.mem = t.i;
		}
		else
		{
			if (t.j > 0)
				t.i = t.mem;
			t.j = 0;
			if (t.i >= len - ft_strlen(little))
				break ;
		}
		t.i++;
	}
	if (t.j < ft_strlen(little) || len == 0 || ft_strlen(little) > len)
		return (NULL);
	return ((char *)(big + t.i - t.j));
}
/*
int	main(int ac, char **av)
{
	printf("from libft    : %s\n", ft_strnstr(av[1], av[2], av[3][0] - '0'));
	return (0);
}*/
