/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:59:27 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:59:35 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pile	*ft_pileinit(void)
{
	t_pile *pile;

	pile = malloc(sizeof(*pile));
	pile->first = NULL;
	pile->info = NULL;
	return (pile);
}
