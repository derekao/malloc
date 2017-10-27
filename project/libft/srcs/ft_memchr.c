/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:21:48 by semartin          #+#    #+#             */
/*   Updated: 2014/11/10 15:53:04 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	n = n - 1;
	str = (unsigned char *)s;
	while (n-- && *(unsigned char *)str != (unsigned char)c)
		str++;
	if (*(unsigned char *)str == (unsigned char)c)
		return (str);
	else
		return (NULL);
}
