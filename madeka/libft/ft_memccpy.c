/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:49:12 by mdeken            #+#    #+#             */
/*   Updated: 2014/11/12 12:23:40 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void			*index;
	char			*d;
	char			*s;
	unsigned char	c2;

	d = (char *)dst;
	s = (char *)src;
	c2 = (unsigned char)c;
	index = ft_memchr(src, c2, n);
	if (index == NULL)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	while (src++ != index + 1)
		*(d++) = *(s++);
	return (d);
}
