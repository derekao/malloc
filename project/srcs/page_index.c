/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:21:50 by semartin          #+#    #+#             */
/*   Updated: 2017/10/23 11:21:51 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	next_page : if the page is full look for room in the next page : Recusive
**	----------------------------------------------------------------------------
**	add_page_tab : add an adress in the Memory Index
**	----------------------------------------------------------------------------
**  test_page_space : find if there is enought room in the current page
**	----------------------------------------------------------------------------
**	get_page_from_index : Find a page with empty room, if none exit, return NULL
*/

static void	next_page(int addr, int index, int pagesize, size_t *tab)
{
	size_t	*new_page;
	int		lastindex;
	int		i;

	lastindex = pagesize * MALLOC_INDEX_SIZE / sizeof(size_t) - 2;
	if (!(i = 0) && tab[lastindex] == 0)
	{
		new_page = mmap(0, pagesize * MALLOC_INDEX_SIZE,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		tab[lastindex] = (size_t)new_page;
		tab[lastindex + 1] = INDEX_NEXTPAGE;
	}
	else
	{
		tab = (size_t *)tab[lastindex];
		while (tab[i] != 0 && i < lastindex)
			i += 2;
		if (i != lastindex)
		{
			tab[i] = addr;
			tab[i + 1] = index;
		}
		else
			next_page(addr, index, pagesize, tab);
	}
}

void		add_page_tab(size_t addr, int index, size_t *tab_index)
{
	int i;
	int pagesize;

	i = 0;
	pagesize = getpagesize();
	while (tab_index[i] != 0
			&& i < pagesize * MALLOC_INDEX_SIZE / (int)sizeof(size_t) - 2)
	{
		i += 2;
	}
	if (i != pagesize * MALLOC_INDEX_SIZE / sizeof(size_t) - 2)
	{
		tab_index[i] = addr;
		tab_index[i + 1] = index;
	}
	else
	{
		next_page(addr, index, pagesize, tab_index);
	}
}

static void	*test_page_space(void *ptrarea, size_t size)
{
	t_header_memarea	*tmp_header;
	void				*tmp_next;

	tmp_next = ptrarea;
	tmp_header = (t_header_memarea *)ptrarea;
	while (1)
	{
		if ((!tmp_header->bIsFree && tmp_header->total_size > tmp_header->size)
			|| (tmp_header->bIsFree && tmp_header->size < size
				&& tmp_header->total_size > tmp_header->size))
		{
			tmp_next = tmp_next + sizeof(t_header_memarea) + tmp_header->size;
			tmp_header = (t_header_memarea *)tmp_next;
		}
		else if (tmp_header->bIsFree && tmp_header->size
						>= size)
			return ((void *)tmp_header);
		else if (tmp_header->size == tmp_header->total_size)
			return (NULL);
		else
		{
			ft_putendl_fd("ERROR in page_index.c : line 98", 2);
			return (NULL);
		}
	}
}

void		*get_page_from_index(int index, size_t size, size_t *tab)
{
	int		i;
	int		lastindex;
	void	*ptr;

	i = 0;
	lastindex = getpagesize() * MALLOC_INDEX_SIZE / sizeof(size_t) - 2;
	while (i < lastindex && tab[i] != 0)
	{
		if (tab[i + 1] == (size_t)index)
		{
			ptr = test_page_space((void *)tab[i], size);
			if (ptr != NULL)
				return (ptr);
		}
		i += 2;
	}
	if (tab[i] == 0)
		return (NULL);
	else
		return (get_page_from_index(index, size, (size_t *)tab[lastindex]));
}

void		remove_page(void *current, size_t *tab)
{
	int		lastindex;
	int		i;
	int		index;
	int		selected;
	t_header_memarea	*head;

	i = 0;
	index = 0;
	selected = 0;
	lastindex = getpagesize() * MALLOC_INDEX_SIZE / sizeof(size_t) - 2;
	while (i < lastindex)
	{
		if (tab[i] == (size_t)current)
			selected = i;
		else if (tab[i + 1])
			index |= tab[i + 1];
		else if (tab[i] == 0 && tab[i + 1] == 0)
			break;
		i += 2;
	}
	if (selected)
	{
		if (index & tab[selected + 1])
		{
			head = (t_header_memarea *)current;
			tab[selected + 1] = INDEX_FREEDZONE;
			munmap(current, head->total_size + sizeof(t_header_memarea));
			tab[selected] = 0;
		}
	}
}
