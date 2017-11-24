/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadcells.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:53:06 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/24 21:00:27 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned char 	ft_isdeadrange(unsigned short where, size_t min, unsigned short *map)
{
	unsigned short keep;
	unsigned char	count;
	unsigned short lines;

	keep = where;
	count = 0;
	lines = 0;
	if (ft_getmapvalat(map, where) == 1 || where % 16 >= min || where / 16 >= min)
	{
		//printf("%s\n", "On s' en va");
		return (0);
	}
	else
	{
		//printf("%s\n", "On rentre dans le while aux whiles");
		while ((keep / 16) + lines < min && count < 3 && ft_getmapvalat(map, keep + 16 * lines) == 0)
		{
			where = keep + lines * 16;
			count++;
			//printf("lines vaut %d , where vaut %d\n",lines, where);
			while ((where % 16 < min - 1) && ft_getmapvalat(map, where + 1) == 0)
			{
				//printf("HFIUQHFIHQF entre dans while 1 avec where + 1 valant %d\n", where + 1);
				where++;
				count++;
				if (count > 3)
				{
					//printf("%s\n", "parti dans premier sous while");
					return (0);
				}
			}
			//printf("%s %d\n", "premier sous while passe count vaut ",count);
			where = (keep % 16 > 0) ? (keep + lines * 16) : 0;
			while ((where % 16 > 0) && ft_getmapvalat(map, where - 1) == 0)
			{
				where--;
				count++;
				if (count > 3)
				{
					//printf("%s\n", "parti dans 2e sous while");
					return (0);
				}
			}
			lines++;
		}
		if (count <= 3)
		{
			//printf("%s %d\n","parti apres avec count de ",count);
			return (count);
		}
		else
		{
			//printf("%s\n", "parti a la fin");
			return (0);
		}
	}
}

unsigned	short	ft_getdcnum(unsigned short *map, size_t min)
{
	size_t i;
	unsigned short ndc;
	unsigned short dc;

	i = 0;
	dc = 0;
	ndc = 0;
	while (i < 16 * min)
	{
		if (ft_isbegdeadrange(map, i, min))
		{
			//printf("Un dead range a %zu\n",i);
			ndc = ft_isdeadrange(i, min, map);
			//printf("Cells du deadrange de %d\n",ndc);
			dc = dc + ndc;
		}
		if (i % 16 >= min - 1 && (i / 16) <= min - 1)
			i += (16 - min + 1);
		else
			i++;
	}
	return (dc);
}
