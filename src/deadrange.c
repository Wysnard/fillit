/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:00:27 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/26 15:05:30 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	ft_getmapvallc(unsigned short *map, unsigned short lin, unsigned short col)
{
	return (ft_getbitat(map[lin], 15 - col));
}

unsigned char gmv(unsigned short *map, unsigned short where)
{
	return (ft_getmapvallc(map, where / 16, where % 16));
}

unsigned char ft_isbegdeadrange(unsigned short *map, unsigned short where, size_t min)
{
	if (gmv(map, where) == 1)
		return (0);
	if (!(where / 16) && !(where % 16))
		return (1);
	if (!(where / 16) && gmv(map, where - 1))
		return (1);
	if (!(where % 16) && (gmv(map ,where - 16) && (gmv(map ,where - 15) || gmv(map ,where + 1))))
		return (1);
	if ((where % 16 == min - 1) && (gmv(map, where - 16) && gmv(map, where - 1)))
		return (1);
	if ((where % 16 == min - 2) && gmv(map, where - 16) && !(!gmv(map, where - 15) && !gmv(map, where + 1)) && gmv(map, where - 1))
		return (1);
	if ((where % 16 <= min - 3) && gmv(map, where - 16) &&
		!(!gmv(map, where - 15) && !gmv(map, where + 1)) &&
		gmv(map, where - 1))
	{
		if (gmv(map, where - 15) && !gmv(map, where + 1))
		{
			if (gmv(map, where - 14))
				return (1);
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
