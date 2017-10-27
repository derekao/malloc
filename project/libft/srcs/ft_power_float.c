/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:57:11 by semartin          #+#    #+#             */
/*   Updated: 2016/02/25 11:57:12 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power_float(double x, int p)
{
	int		i;
	double	nb;

	if (p == 0)
		return (1.0);
	i = 0;
	nb = 1.0;
	if (p > 0)
	{
		while (i < p)
		{
			nb *= x;
			i++;
		}
	}
	else
	{
		while (i > p)
		{
			nb /= x;
			i--;
		}
	}
	return (nb);
}
