/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:43:40 by semartin          #+#    #+#             */
/*   Updated: 2014/11/14 13:30:59 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, char const *s2, size_t n)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	k = -1;
	j = 0;
	i = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		j = ft_strlen(s2);
	if ((size_t)j > n)
		j = n;
	if ((str = malloc(sizeof(*str) * (i + j + 1))) == 0)
		return (NULL);
	while (++k < i)
		str[k] = s1[k];
	while (k++ < (i + j))
		str[k - 1] = s2[k - i - 1];
	str[k - 1] = 0;
	free(s1);
	return (str);
}
