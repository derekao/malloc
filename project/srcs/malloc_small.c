/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:28:04 by semartin          #+#    #+#             */
/*   Updated: 2017/10/23 13:28:04 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	ft_malloc_small : Return the allocated area
**						between MALLOC_SMALL and MALLOC_LARGE
*/

void	*ft_malloc_small(size_t size, size_t *tab_index)
{
	void *current;

	current = getcurrentpage(size, INDEX_SMALL, tab_index);
	return (current + sizeof(t_header_memarea));
}
