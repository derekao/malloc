/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:37:49 by semartin          #+#    #+#             */
/*   Updated: 2014/11/07 14:15:55 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while ((unsigned char)c != *(unsigned char *)src && n)
	{
		n--;
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	if ((n == 0 && (unsigned char)c != *(unsigned char *)src))
		return (NULL);
	else
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		return (dst);
	}
}
