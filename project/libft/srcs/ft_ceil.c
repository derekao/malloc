/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:32:36 by semartin          #+#    #+#             */
/*   Updated: 2016/04/11 12:32:36 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	functions return the smallest integral value greater than or equal to x.
*/

int	ft_ceil(double x)
{
	return ((int)(x + 0.9999999999));
}
