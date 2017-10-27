/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:26:51 by semartin          #+#    #+#             */
/*   Updated: 2014/11/04 16:10:13 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)dst;
	if (dst < src)
	{
		while (len--)
			*str++ = *(unsigned char *)src++;
	}
	else if (dst == src)
		return (dst);
	else
	{
		while (len--)
			*(str + len) = *(unsigned char*)(src + len);
	}
	return (dst);
}
