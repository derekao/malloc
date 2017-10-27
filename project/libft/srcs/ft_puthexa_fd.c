/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:28:00 by semartin          #+#    #+#             */
/*   Updated: 2014/11/06 17:44:17 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa_fd(size_t n, int fd)
{
	if (n >= 16)
	{
		ft_puthexa_fd(n / 16, fd);
		ft_puthexa_fd(n % 16, fd);
	}
	else if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(n + 'a' - 10, fd);
	}
}
