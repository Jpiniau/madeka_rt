/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:26:55 by mdeken            #+#    #+#             */
/*   Updated: 2014/11/04 12:48:48 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		length;

	ptr = NULL;
	if (src != NULL)
	{
		length = ft_strlen(src);
		ptr = (char *)malloc(sizeof(char) * (length + 1));
		ft_strcpy(ptr, src);
	}
	return (ptr);
}
