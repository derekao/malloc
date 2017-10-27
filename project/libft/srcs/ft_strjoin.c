/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:43:40 by semartin          #+#    #+#             */
/*   Updated: 2014/11/10 16:24:12 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	k = -1;
	i = 0;
	j = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		j = ft_strlen(s2);
	if ((str = malloc(sizeof(*str) * (i + j + 1))) == 0)
		return (NULL);
	while (++k < i)
		str[k] = s1[k];
	while (k < (i + j))
	{
		str[k] = s2[k - i];
		k++;
	}
	str[k] = 0;
	return (str);
}
