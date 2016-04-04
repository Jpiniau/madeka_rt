/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclrone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:36:07 by mdeken            #+#    #+#             */
/*   Updated: 2014/11/27 13:50:21 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclrone(t_list **alst)
{
	t_list	*del;

	if (alst != NULL && *alst != NULL)
	{
		del = *alst;
		(*alst)->content = NULL;
		(*alst)->content_size = 0;
		*alst = (*alst)->next;
		free(del);
	}
}
