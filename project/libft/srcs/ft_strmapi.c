/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:55:17 by semartin          #+#    #+#             */
/*   Updated: 2014/11/10 17:32:48 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				nb;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	nb = 0;
	while (s[nb])
		nb++;
	str = malloc(sizeof(*str) * (nb + 1));
	while (s[i])
	{
		*str = (*f)(i, s[i]);
		str++;
		i++;
	}
	*str = 0;
	return (str - nb);
}
