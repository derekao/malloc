/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:53:12 by semartin          #+#    #+#             */
/*   Updated: 2014/11/10 17:42:20 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		j[2];
	int		k;
	char	*str;

	if (!s || (str = malloc(sizeof(*str) * (ft_strlen(s) + 1))) == 0)
		return (NULL);
	j[0] = 0;
	k = 0;
	while (s[j[0]] && (s[j[0]] == ' ' || s[j[0]] == '\n' || s[j[0]] == '\t'))
		j[0]++;
	while (s[j[0]])
	{
		if (s[j[0]] == ' ' || s[j[0]] == '\n' || s[j[0]] == '\t')
		{
			j[1] = j[0];
			while (s[j[0]] == ' ' || s[j[0]] == '\n' || s[j[0]] == '\t')
				j[0]++;
			if (s[j[0]] == '\0')
				return (str);
			j[0] = j[1];
		}
		str[k++] = s[j[0]++];
		str[k] = 0;
	}
	return (str);
}
