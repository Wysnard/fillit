/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:57:44 by vlay              #+#    #+#             */
/*   Updated: 2017/11/11 10:20:43 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned	char	*sr;
	unsigned	char	*sd;

	i = 0;
	sr = (unsigned char *)s1;
	sd = (unsigned char *)s2;
	while (i < n && (sr[i] || sd[i]))
	{
		if (sr[i] != sd[i])
			return (sr[i] - sd[i]);
		i++;
	}
	return (0);
}
