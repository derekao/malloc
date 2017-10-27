/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:58:42 by semartin          #+#    #+#             */
/*   Updated: 2014/11/10 17:17:25 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*s2 == 0)
		return ((char *)(s1));
	while (s1[i] && (unsigned char)s1[i] != (unsigned char)s2[j] && i < n)
		i++;
	if (s1[i] == 0 || i > n)
		return (NULL);
	else if ((unsigned char)s1[i] == (unsigned char)s2[j])
	{
		while ((unsigned char)s2[j] == (unsigned char)s1[i + j]
				&& s2[j] && i + j < n)
			j++;
		if (s2[j] == 0)
			return ((char *)(s1 + i));
		else if (i++ + j >= n)
			return (NULL);
		else
			return (ft_strnstr(s1 + i, s2, n - i));
	}
	return (NULL);
}
