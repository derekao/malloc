/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:47:31 by semartin          #+#    #+#             */
/*   Updated: 2017/10/23 10:47:32 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	set_page_headers : if the area is two times bigger than size, split it
**	----------------------------------------------------------------------------
**	getcurrentpage : Get the current free area
**						Used for malloc_small aswell
**	----------------------------------------------------------------------------
**	fill_next : Norme made me do this horror
**	----------------------------------------------------------------------------
**	ft_malloc_tiny : Return the allocated area
**						between MALLOC_TINY and MALLOC_SMALL
*/

static void	set_page_headers(void *tmp, size_t size)
{
	t_header_memarea *header;
	t_header_memarea *next;
	t_header_memarea *newnext;

	header = (t_header_memarea *)tmp;
	if (header->size >= size * 2 && header->size >= sizeof(t_header_memarea)
			+ size && (header->total_size - size
		- sizeof(t_header_memarea)) > sizeof(t_header_memarea) + MALLOC_TINY)
	{
		newnext = (t_header_memarea *)((void *)header + size
					+ sizeof(t_header_memarea));
		newnext->size = header->size - size - sizeof(t_header_memarea);
		newnext->total_size = header->total_size - size
								- sizeof(t_header_memarea);
		newnext->previous_header = (size_t)header;
		newnext->bIsFree = 1;
		if (header->size != header->total_size)
		{
			next = (t_header_memarea *)(tmp + size + sizeof(t_header_memarea));
			next->previous_header = (size_t)newnext;
		}
		header->size = size;
	}
	header->bIsFree = 0;
}

static void	fill_next(t_header_memarea *next, t_header_memarea *tmpheader,
						size_t size)
{
	tmpheader->size = size;
	tmpheader->previous_header = 0;
	tmpheader->bIsFree = 0;
	next->size = tmpheader->total_size - tmpheader->size
		- sizeof(t_header_memarea);
	next->total_size = next->size;
	next->bIsFree = 1;
	next->previous_header = (size_t)tmpheader;
}

void		*getcurrentpage(size_t size, int page_index, size_t *tab_index)
{
	void				*tmp;
	t_header_memarea	*tmpheader;
	t_header_memarea	*next;
	size_t				malloc_size;

	if (page_index == INDEX_TINY)
		malloc_size = MALLOC_TINY_PAGES;
	else if (page_index == INDEX_SMALL)
		malloc_size = MALLOC_SMALL_PAGES;
	tmp = get_page_from_index(page_index, size, tab_index);
	if (tmp == NULL)
	{
		tmp = mmap(0, getpagesize() * malloc_size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		if (tmp == NULL)
			return (NULL);
		tmpheader = (t_header_memarea *)tmp;
		tmpheader->total_size = getpagesize() * malloc_size
								- sizeof(t_header_memarea);
		next = (t_header_memarea *)(tmp + size + sizeof(t_header_memarea));
		fill_next(next, tmpheader, size);
		add_page_tab((size_t)tmp, page_index, tab_index);
	}
	set_page_headers(tmp, size);
	return (tmp);
}

void		*ft_malloc_tiny(size_t size, size_t *tab_index)
{
	void *current;

	current = getcurrentpage(size, INDEX_TINY, tab_index);
	return (current + sizeof(t_header_memarea));
}
