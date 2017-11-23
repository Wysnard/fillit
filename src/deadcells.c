/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadcells.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:53:06 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/23 15:52:02 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	ft_isdeadrange(unsigned short where, unsigned char read, unsigned int min, unsigned short *map)
{
	if(ft_getmapvalat(map, where) == 1 && read <= 3)
		return (read);
	else if (read > 3)
		return (0);
	else if ((where % min) < (min + 1))
		ft_isdeadrange(where + 1, read + 1, min, map);
	else if ((where / 16) >= min)
		ft_isdeadrange(where + min, read + 1, min, map);
	return (read);
}
