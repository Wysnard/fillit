#include "libft.h"

int	ft_cttetris(char *buf)
{
	size_t	i;
	size_t	n;
	size_t	pt;

	i = 0;
	n = 0;
	pt = 0;
	if (buf[4] != '\n' && buf[8] != '\n' && buf[12] != '\n' && buf[16] != '\n')
		return (0);
	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			n++;
		if (buf[i] == '.')
			pt++;
		i++;
	}
	if (pt != 12 || buf[i - 1] != '\n')
		return (0);
	return (n);
}
