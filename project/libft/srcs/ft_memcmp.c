/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:32:25 by semartin          #+#    #+#             */
/*   Updated: 2014/11/09 16:23:39 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	n = n - 1;
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && n--
			&& *(unsigned char *)s1)
	{
		s1++;
		s2++;
	}
	if (*(unsigned char *)s1 == *(unsigned char *)s2)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
