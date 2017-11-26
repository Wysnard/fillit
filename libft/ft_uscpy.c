/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uscpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:21:58 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/26 17:21:59 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	*ft_uscpy(unsigned short *dest, unsigned short *src, size_t len)
{
	while (len)
	{
		*dest++ = *src++;
		len -= 1;
	}
	return (dest);
}
