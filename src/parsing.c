#include "libft.h"

int	ft_cttetris(char *buf)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			n++;
		i++;
	}
	return (n);
}
