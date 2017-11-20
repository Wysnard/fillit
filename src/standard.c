#include "fillit.h"

unsigned	char	ft_heightlength(unsigned short c)
{
	unsigned	char	hl;
	size_t	i;

	i = 0;
	hl = 0;
	while (i < 16)
	{
		if (HEIGHTMASK & (c << i))
			hl += 1;
		i += 4;
	}
	hl = hl << 4;
	i = 0;
	while (i < 4)
	{
		if (LENGTHMASK & (c << i))
			hl += 1;
		i += 1;
	}
	return (hl);
}

unsigned	short	ft_standard(unsigned short c)
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
