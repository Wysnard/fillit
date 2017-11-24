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


unsigned char	ft_get1inbyte(unsigned short byte)
{
	int i;
	int	one;

	i = 0;
	one = 0;
	while (i < 16)
	{
		byte >>= 1;
		if (byte & 1)
			one++;
		i++;
	}
	return (one);
}

unsigned char	ft_getbitat(unsigned short byte, unsigned short at)
{
	char	ret;
	ret = ((byte >> at) & 1);
	return (ret);
}

unsigned char ft_getconn0inline(unsigned short line)
{
	unsigned char at;
	unsigned char zer;
	unsigned char	maxzer;

	at = 0;
	zer = 0;
	maxzer = 0;
	while (at < 16)
	{
		if (ft_getbitat(line, at) == 0)
			zer++;
		else
		{
			maxzer = (maxzer > zer) ? maxzer : zer;
			zer = 0;
		}
		at++;
	}
	maxzer = (maxzer > zer) ? maxzer : zer;
	return (maxzer);
}

unsigned char	ft_getenvgtet(unsigned char tet)
{
	if (ft_issqrtet(tet))
		return (2);
	else if (ft_isdwbtet(tet))
		return (4);
	else if (ft_isupbtet(tet))
		return (1);
	else if (ft_isdwrtet(tet))
		return ft_get1inbyte((tet << 2) & 0b11100000);
	else if (ft_isuprtet(tet))
		return ft_get1inbyte((tet << 2) & 0b11000000);
	return (0);
}
