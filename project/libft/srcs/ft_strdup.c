/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:41:05 by semartin          #+#    #+#             */
/*   Updated: 2015/01/22 12:43:07 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		nb;

	i = 0;
	nb = ft_strlen(s1);
	if (nb == 0)
	{
		s2 = malloc(sizeof(*s1));
		*s2 = 0;
		return (s2);
	}
	s2 = malloc(sizeof(*s1) * (nb + 1));
	while (i < nb)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
