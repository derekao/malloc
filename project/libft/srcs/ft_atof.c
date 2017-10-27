/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 16:27:47 by semartin          #+#    #+#             */
/*   Updated: 2015/09/12 16:53:07 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_atof : Convert the initial portion of str into a double
*/

static double	ft_deci(char *str, double i)
{
	int deci;

	deci = -1;
	str++;
	while (*str >= '0' && *str <= '9' && *str)
		i = i + ((*str++ - '0') * ft_power_float(10, deci--));
	return (i);
}

double			ft_atof(char *str)
{
	double		i;

	i = 0;
	while ((*str >= 0 && *str <= 26) || (*str >= 28 && *str <= 32))
		str++;
	if (*str == '-')
	{
		str++;
		while (*str >= '0' && *str <= '9' && *str)
			i = (i * 10) + *str++ - '0';
		if (*str == '.')
			i = ft_deci(str, i);
		return (-i);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
		i = (i * 10) + *str++ - '0';
	if (*str == '.')
		i = ft_deci(str, i);
	return (i);
}
