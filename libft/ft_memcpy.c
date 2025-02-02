/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:36 by salmou            #+#    #+#             */
/*   Updated: 2024/11/13 20:51:16 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*ptr;
	const char	*csrc;

	if (!dest && !src)
		return (NULL);
	ptr = (char *)dest;
	csrc = (const char *)src;
	while (len--)
		ptr[len] = csrc[len];
	return (dest);
}
/*#include "stdio.h"
int	main(void)
{
	char	dest[] = "cake is good";
	char	src[] = "sami";
	ft_memcpy(dest, src, 4);
	int i = 0;
	while(i)
		printf("%d \n", dest[i++]);
*/
