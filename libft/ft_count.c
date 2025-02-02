#include "libft.h"

size_t	ft_car_count(char const *s, char c)
{
	size_t	i;
	size_t	car;

	i = 0;
	car = 0;
	while (s[i])
		if (s[i++] == c)
			car++;
	return (car);
}
