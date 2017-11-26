/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:31:52 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 17:03:06 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	stdr(unsigned short c)
{
	if (c == 0)
		return (0);
	while (!(HEIGHTMASK & c))
		c = c << 4;
	while (!(LENGTHMASK & c))
		c = c << 1;
	return (c);
}

int				ft_hl(unsigned short c, unsigned char *h, unsigned char *l)
{
	size_t	i;
	size_t	j;

	i = 0;
	*h = 0;
	*l = 0;
	j = 0;
	while (i < 16)
	{
		if (HEIGHTMASK & (c << i))
			(*h) = j;
		i = 4 * j++;
	}
	i = 0;
	while (i < 4)
	{
		if (LENGTHMASK & (c << i))
			(*l) = i + 1;
		i += 1;
	}
	if (*h == 0 || *l == 0 || !ft_checkjumps(c, *h, *l))
		return (0);
	return (1);
}

unsigned char	ft_checkjumps(unsigned short c, unsigned char h,
				unsigned char l)
{
	if (h == 2 && l == 3)
		if ((c >> 13) == 5 || ((c << 4) >> 13) == 5)
			return (0);
	if (h == 3 && l == 2)
		if ((c & LENGTHMASK) == DEG_JUMP || ((c << 1) & LENGTHMASK) == DEG_JUMP)
			return (0);
	return (1);
}
