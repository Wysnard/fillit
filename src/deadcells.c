/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadcells.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:04:20 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/26 14:17:20 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned char 	ft_isdeadrange(unsigned short where, size_t min, unsigned short *map)
{
	unsigned short keep;
	unsigned char	count;
	unsigned short lines;
	unsigned short dec;

	keep = where;
	count = 0;
	lines = 0;
	dec = 0;
	if (gmv(map, where) == 1 || where % 16 >= min || where / 16 >= min)
		return (0);
	else
	{
		while ((keep / 16) + lines < min && count <= 3)
		{
			where = keep + lines * 16;
			if (gmv(map, where) && lines > 0)
			{
				if ((where % 16 < min - 1) && !gmv(map, where + 1) && !gmv(map, where - 15))
					dec++;
				else if ((where % 16 > 0) && !gmv(map, where - 1) && !gmv(map, where - 17))
					dec--;
				else
					break;
			}
			where += dec;
			count++;
			while ((where % 16 < min - 1) && gmv(map, where + 1) == 0)
			{
				where++;
				count++;
				if (count > 3)
				{
					return (0);
				}
			}
			where = (keep % 16 > 0) ? (keep + lines * 16 + dec) : 0;
			while ((where % 16 > 0) && gmv(map, where - 1) == 0)
			{
				where--;
				count++;
				if (count > 3)
					return (0);
			}
			lines++;
		}
		if (count <= 3)
			return (count);
		else
			return (0);
	}
}

unsigned	short	ft_getdcnum(unsigned short *map, size_t min)
{
	size_t i;
	unsigned short dc;

	i = 0;
	dc = 0;
	while (i < 16 * min)
	{
		if (ft_isbegdeadrange(map, i, min))
			dc = dc + ft_isdeadrange(i, min, map);
		if (i % 16 >= min - 1 && (i / 16) <= min - 1)
			i += (16 - min + 1);
		else
			i++;
	}
	return (dc);
}
