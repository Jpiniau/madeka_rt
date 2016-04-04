/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 15:42:55 by mdeken            #+#    #+#             */
/*   Updated: 2014/12/10 16:03:08 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **begin, t_list *new)
{
	if (begin != NULL)
	{
		if (*begin == NULL)
		{
			*begin = new;
		}
		else if ((*begin)->next == NULL)
			(*begin)->next = new;
		else
		{
			return (ft_lstaddback(&(*begin)->next, new));
		}
	}
}
