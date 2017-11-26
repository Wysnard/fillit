/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:06:33 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 22:42:49 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	unsigned short		*map;
	int					fd;
	t_etris				tetris;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0 || !(ft_read(fd, &tetris)))
		{
			ft_putstr("error\n");
			return (1);
		}
		if (!(map = (unsigned short *)malloc(sizeof(short) * tetris.min)))
			return (1);
		ft_initmap(map, tetris.min);
		while ((ft_solve(&tetris, map, tetris.min, 0) == 0))
			ft_initmap(map, ++tetris.min);
		if (!ft_printresulttab(&tetris))
			return (1);
		free(map);
	}
	else
		ft_putstr("usage: fillit map_file\n");
	return (0);
}
