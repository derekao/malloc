/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:22:30 by semartin          #+#    #+#             */
/*   Updated: 2017/10/23 15:22:31 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	set_large_header : Set the header of the large allocated area
**	----------------------------------------------------------------------------
** 	ft_malloc_large  : Return the allocated area
**						between MALLOC_SMALL and MALLOC_LARGE
*/

static void	set_large_header(void *current, int nbpage)
{
	t_header_memarea *header;

	header = (t_header_memarea *)current;
	header->size = nbpage * getpagesize() - sizeof(t_header_memarea);
	header->total_size = header->size;
	header->bIsFree = 0;
	header->previous_header = 0;
}

void		*ft_malloc_large(size_t size, size_t *tab_index)
{
	void	*current;
	int		nbpage;

	nbpage = (size + sizeof(t_header_memarea)) / getpagesize() + 1;
	current = mmap(0, getpagesize() * nbpage,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (current == NULL)
		return (NULL);
	set_large_header(current, nbpage);
	add_page_tab((size_t)current, INDEX_LARGE, tab_index);
	return (current + sizeof(t_header_memarea));
}
