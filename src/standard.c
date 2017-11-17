#include "fillit.h"

unsigned	char	ft_formrect(unsigned char hl, unsigned short tetris)
{
	unsigned	char	form_part;
	unsigned	char	tet_part;
	unsigned	short	i;

	i = 15;
	tet_part = 0;
	form_part = 0;
	if (hl >> 4 == 3)
	{
		form_part = 1 << 6;
		while (i >= 6)
		{
			tet_part = tet_part + (ft_power(2, i) & tetris);
			// ft_putnbr(i);
			// ft_putchar('\n');
			// ft_putnbr(ft_power(2,i));
			// ft_putchar('\n');
			// ft_print_bits(ft_power(2,i), 15);
			// ft_putchar('\n');
			// ft_print_bits(tetris, 15);
			// ft_putchar('\n');
			if (i % 4 == 2)
			{
				i -= 3;
			}
			else
				i--;
		}
	}
	else if (hl >> 4 == 2)
	{
		while (i >= 10)
		{
			tet_part = tet_part + (ft_power(2, i) & tetris);
			if (i % 4 == 2)
				i -= 2;
			else
				i--;
		}
	}
	return (form_part + tet_part);
}

unsigned	char	ft_putinchar(unsigned short c)
{
	unsigned	char	hl;
	unsigned	char	bits;

	bits = 0;
	hl = ft_heightlength(c);
	if ((hl >> 4) == 4)
		bits = 5 << 5;
	else if ((hl & 15) == 4)
		bits = 1 << 7;
	else if ((hl >> 4) == 3 || (hl & 15) == 3)
	{
		if (!(bits = ft_formrect(hl, c)))
			return (0);
	}
	else if ((hl >> 4) == 2 && (hl & 15) == 2)
		bits = 3 << 6;
	return (bits);
}
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
