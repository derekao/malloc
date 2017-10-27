/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:52:26 by semartin          #+#    #+#             */
/*   Updated: 2014/11/07 12:29:01 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char *ptr;

	if (c == 0)
		return ((char*)s + ft_strlen(s));
	ptr = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			ptr = str;
		str++;
	}
	if (ptr != NULL)
		return (ptr);
	else
		return (NULL);
}
