/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:09:56 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/18 17:13:56 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_initmap(unsigned short **map, size_t max)
{
	size_t			i;

	i = 0;
	if (max == 0)
		return ;
	while (i < max)
		(*map)[i++] = 0;
	return ;
}
