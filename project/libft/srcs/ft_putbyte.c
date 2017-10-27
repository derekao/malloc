/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:01:11 by semartin          #+#    #+#             */
/*   Updated: 2017/10/27 15:01:11 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbyte(unsigned char n)
{
	unsigned char tmp;

	tmp = n / 16;
	if (tmp < 10)
		ft_putchar(tmp + '0');
	else
		ft_putchar(tmp + 'a' - 10);
	n %= 16;
	if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 'a' - 10);
}