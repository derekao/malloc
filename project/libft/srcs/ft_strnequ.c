/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:25:58 by semartin          #+#    #+#             */
/*   Updated: 2014/11/07 14:19:46 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && i < n - 1)
	{
		if (s1[i] == 0)
			return (1);
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
