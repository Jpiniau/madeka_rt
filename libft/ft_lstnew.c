/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:43:51 by mdeken            #+#    #+#             */
/*   Updated: 2014/11/10 17:25:48 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem != NULL)
	{
		if (content == NULL)
		{
			elem->content_size = 0;
			elem->content = NULL;
		}
		else
		{
			elem->content = (void *)malloc(content_size);
			if (elem->content)
				elem->content = ft_memcpy(elem->content, content, content_size);
			elem->content_size = content_size;
			elem->next = NULL;
		}
	}
	return (elem);
}
