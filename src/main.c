/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:06:33 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 14:30:16 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned	short	*map;
	int	fd;
	size_t	len;
	t_etris	tetris;
	size_t	i;
	char **resulttab;

	i = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0 || !(ft_read(fd, &tetris)))
		{
			ft_putstr("error\n");
			return (1);
		}
		if (!(map = (unsigned short *)malloc(sizeof(unsigned short) * tetris.min)))
			return (1);
		ft_initmap(map, tetris.min);
		while ((ft_solve(&tetris, map, tetris.min, 0) == 0))
			ft_initmap(map, ++tetris.min);
		if (!(resulttab = ft_initresulttab(tetris.min)))
			return (0);
		i = 0;
		len = ft_strlen((const char*)tetris.h);
		while (i < len)
		{
			ft_fillresulttab(resulttab, tetris.at[i], i, &tetris);
			i += 1;
		}
		i = 0;
		while (i < tetris.min)
		{
			ft_putstr(resulttab[i]);
			i++;
		}
		free(map);
	}
	else
		ft_putstr("usage: fillit map_file\n");
	return (0);
}
