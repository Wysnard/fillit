#include "fillit.h"

void	ft_heightlength(unsigned short c, char *height, char *length)
{
	size_t	i;

	i = 0;
	*length = 0;
	*height = 0;
	while (i < 4)
	{
		if (34952 & (c << i))
			(*length) += 1;
		i += 1;
	}
	i = 0;
	while (i < 16)
	{
		if (61440 & (c << i))
			(*height) += 1;
		i += 4;
	}
}

unsigned	short	ft_standard(unsigned short c)
{
	if (c == 0)
		return (0);
	while (!(61440 & c))
		c = c << 4;
	while (!(34952 & c))
		c = c << 1;
	return (c);
}
