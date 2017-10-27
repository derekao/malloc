/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:58:42 by semartin          #+#    #+#             */
/*   Updated: 2014/11/07 12:48:13 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] && s1[i] != s2[j])
		i++;
	if (s1[i] == 0)
		return (NULL);
	else if (s1[i] == s2[j])
	{
		while (s2[j] == s1[i + j] && s2[j])
			j++;
		if (s2[j] == 0)
			return ((char *)(s1 + i));
		else
		{
			i++;
			return (ft_strstr(s1 + i, s2));
		}
	}
	return (NULL);
}
