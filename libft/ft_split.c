/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 03:51:17 by salmou            #+#    #+#             */
/*   Updated: 2024/11/28 22:22:55 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_count(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		flag;

	i = 0;
	words = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && !flag)
		{
			words++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

static size_t	ft_wgetfirst(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static size_t	ft_wgetlast(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	ft_free(char **ptr, size_t i)
{
	while (i > 0)
		free(ptr[i--]);
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	t_search	t;
	char		**ptr;
	char		*ptr_tmp;

	words = ft_words_count(s, c);
	ptr = (char **)malloc((words + 1) * sizeof(char *));
	if (!ptr || !s)
		return (NULL);
	t.mem = 0;
	t.j = 0;
	while (t.j < words)
	{
		t.i = ft_wgetfirst(s + t.mem, c);
		ptr_tmp = ft_substr(s + t.mem, t.i, ft_wgetlast(s + t.mem + t.i, c));
		if (!ptr_tmp)
		{
			ft_free(ptr, t.j);
			return (NULL);
		}
		t.mem += t.i + ft_wgetlast(s + t.mem + t.i, c);
		ptr[t.j++] = ptr_tmp;
	}
	ptr[t.j] = NULL;
	return (ptr);
}
/*
int	main(int ac, char **av)
{
	char	**ptr;
	int	i = 0;

	ptr = ft_split(av[1], av[2][0]);
	while(ptr[i])
		printf("%s\n", ptr[i++]);
}*/
