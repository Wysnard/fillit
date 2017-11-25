/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:02:27 by vlay              #+#    #+#             */
/*   Updated: 2017/11/25 21:02:59 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char			i;

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

unsigned	char	ft_getbitat(unsigned short byte, unsigned short at)
{
	char	ret;

	ret = ((byte >> at) & 1);
	return (ret);
}
