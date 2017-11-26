#include "fillit.h"

unsigned	short	std(unsigned short c)
{
	if (c == 0)
		return (0);
	while (!(HEIGHTMASK & c))
		c = c << 4;
	while (!(LENGTHMASK & c))
		c = c << 1;
	return (c);
}

int	ft_hl(unsigned short c, unsigned char *h, unsigned char *l)
{
	size_t	i;

	i = 0;
	*h = 0;
	*l = 0;
	while (i < 16)
	{
		if (HEIGHTMASK & (c << i))
			(*h) += 1;
		i += 4;
	}
	i = 0;
	while (i < 4)
	{
		if (LENGTHMASK & (c << i))
			(*l) += 1;
		i += 1;
	}
	if (*h == 0 || *l == 0)
		return (0);
	return (1);
}
