/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:38:22 by semartin          #+#    #+#             */
/*   Updated: 2014/11/05 08:25:42 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (c < 65)
		return (0);
	else if (c <= 90)
		return (1);
	else if (c < 97)
		return (0);
	else if (c <= 122)
		return (1);
	else
		return (0);
}
