#include "fillit.h"

unsigned	short	ft_createmask(size_t min)
{
	unsigned	short	mask;

	mask = 0;
	while (min)
	{
		mask >>= 1;
		mask |= 0x8000;
		min--;
	}
	return (mask);
}

unsigned	short	ft_registerbits(char *buf)
{
	unsigned short	c;
	char		i;

	c = 0;
	i = 15;
	while (i >= 0)
	{
		if (*buf != '.' && *buf != '#' && *buf != '\n')
			return (0);
		if (*buf == '#')
			c = c | (1 << i);
		if (*buf != '\n')
			i -= 1;
		buf += 1;
	}
	return (c);
}

size_t	ft_consecutive_zero(unsigned	short	*map)
{
	size_t	j;
	size_t	i;
	size_t	zero;

	j = 0;
	zero = 0;
	while ()
	{
		i = 0;
		while ()
		{
			while ()
			{
				zero += 1;
				i += 1;
			}
			i += 1;
		}
	}
	return (i);
}
