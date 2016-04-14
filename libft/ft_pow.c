/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:29:58 by mdeken            #+#    #+#             */
/*   Updated: 2016/04/14 19:31:54 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_pow(float x, int y)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	if (y == 0)
		return (1);
	else if (y < 0)
		return (0);
	while (i < y)
	{
		result *= x;
		i++;
	}
	return (result);
}
