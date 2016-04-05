/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:36:29 by mdeken            #+#    #+#             */
/*   Updated: 2014/11/20 17:41:30 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclr(t_list **alst)
{
	t_list *first;
	t_list *tmp;

	if (alst != NULL)
	{
		first = *alst;
		while (first)
		{
			tmp = first->next;
			free(first->content);
			first->content = NULL;
			first->content_size = 0;
			free(first);
			first = tmp;
		}
		*alst = NULL;
	}
}
