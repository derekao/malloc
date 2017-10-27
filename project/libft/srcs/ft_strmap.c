/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:23:51 by semartin          #+#    #+#             */
/*   Updated: 2014/11/10 17:32:02 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		nb;

	if (s && f)
	{
		nb = 0;
		while (s[nb])
			nb++;
		str = malloc(sizeof(*str) * (nb + 1));
		while (*s)
		{
			*str = (*f)(*s++);
			str++;
		}
		*(str) = 0;
		return (str - nb);
	}
	return (NULL);
}
