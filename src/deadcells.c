/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadcells.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:53:06 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/24 17:59:17 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned char 	ft_isdeadrange(unsigned short where, unsigned int min, unsigned short *map)
{
	unsigned short keep;
	unsigned char	count;
	unsigned short lines;

	keep = where;
	count = 0;
	lines = 0;
	if (ft_getmapvalat(map, where) == 1 || where % 16 >= min || where / 16 >= min || where == (min + 1) * (min - 1))
		return (0);
	else
	{
		while ((keep / 16) + lines < min && count < 3)
		{
			where = keep + lines * 16;
			while ((where % 16 < min - 1) && ft_getmapvalat(map, where) == 0)
			{
				count++;
				if (count > 3)
					return (0);
				where++;
			}
			where = keep + lines * 16;
			while ((where % 16 >= 0) && ft_getmapvalat(map, where) == 0)
			{
				count++;
				if (count > 3)
					return (0);
				where--;
			}
			lines++;
		}
		if (count <= 3)
			return (count);
		else
			return (0);
	}
}
