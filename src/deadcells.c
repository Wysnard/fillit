/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadcells.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:04:20 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/26 17:29:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned char	ft_isdeadrange(unsigned short where, size_t min,
				unsigned short *map)
{
	unsigned char	count;

	count = 0;
	if (gmv(map, where) == 1 || (where & 15) >= min || where / 16 >= min)
		return (0);
	count = ft_deadrangevert(where, min, map);
	return (count <= 3) ? count : 0;
}

unsigned char	ft_deadrangevert(unsigned short where, size_t min,
				unsigned short *map)
{
	unsigned short	k;
	unsigned char	count;
	unsigned short	l;
	short			dec;

	k = where;
	count = 0;
	l = 0;
	dec = 0;
	while (((k / 16) + l < min && count <= 3) && ((where = k + l * 16) >= 0))
	{
		if ((dec = ft_deadrangedec(map, where, l, min)) == 10)
			break ;
		where += dec;
		count++;
		while (((where & 15) < min - 1) && gmv(map, ++where) == 0)
			if (count++ > 3)
				return (0);
		where = ((k & 15) > 0) ? (k + l * 16 + dec) : 0;
		while (((where & 15) > 0) && gmv(map, --where) == 0)
			if (count++ > 3)
				return (0);
		l++;
	}
	return (count);
}

short			ft_deadrangedec(unsigned short *map, unsigned short where,
				unsigned short lines, size_t min)
{
	short dec;

	dec = 0;
	if (gmv(map, where) && lines > 0)
	{
		if (((where & 15) < min - 1) && !gmv(map, where + 1)
			&& !gmv(map, where - 15))
			dec++;
		else if (((where & 15) > 0) && !gmv(map, where - 1)
				&& !gmv(map, where - 17))
			dec--;
		else
			dec = 10;
	}
	return (dec);
}

unsigned short	ft_getdcnum(unsigned short *map, size_t min)
{
	size_t			i;
	unsigned short	dc;

	i = 0;
	dc = 0;
	while (i < 16 * min)
	{
		if (ft_isbegdeadrange(map, i, min))
			dc = dc + ft_isdeadrange(i, min, map);
		if ((i & 15) >= min - 1 && (i / 16) <= min - 1)
			i += (16 - min + 1);
		else
			i++;
	}
	return (dc);
}
