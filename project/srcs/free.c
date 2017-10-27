/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:18:47 by semartin          #+#    #+#             */
/*   Updated: 2017/10/23 17:18:48 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	check_inarea : Check if ptr is a ptr that we allocated and not
**					some random ptr of the allocated area
**	----------------------------------------------------------------------------
**	check_entry : Check if the ptr is in the Heap
**	----------------------------------------------------------------------------
**  abort_free : Abort if the ptr has already been freed
**	----------------------------------------------------------------------------
**	free : Free the ptr
*/

static int	check_inarea(void *mem, void *ptr)
{
	t_header_memarea	*head;

	head = (t_header_memarea *)mem;
	while (head)
	{
		if ((void *)head + sizeof(t_header_memarea) == ptr)
			return (1);
		if (head->size != head->total_size)
			head = (t_header_memarea *)((void *)head + head->size
						+ sizeof(t_header_memarea));
		else
			head = NULL;
	}
	return (0);
}

int			check_entry(void *ptr, size_t *tmp)
{
	t_header_memarea	*head;
	int					lastindex;
	int					i;

	if (ptr == NULL)
		return (0);
	i = 0;
	lastindex = getpagesize() * MALLOC_INDEX_SIZE / sizeof(size_t) - 2;
	while (i < lastindex)
	{
		if (tmp[i] == 0 && tmp[i + 1] == INDEX_FREEDZONE)
		{
			i += 2;
			continue;
		}
		else if (tmp[i] == 0 && tmp[i + 1] == 0)
			return (0);
		head = (t_header_memarea *)tmp[i];
		if (ptr >= (void *)tmp[i] && ptr <= (void *)tmp[i] + head->total_size)
			return (check_inarea((void *)tmp[i], ptr));
		i += 2;
	}
	return (check_entry(ptr, (size_t *)tmp[lastindex]));
}

static void	abort_free(void *ptr)
{
	if (ptr == NULL)
		return;
	ft_putstr_fd("Malloc error for object : 0x", 2);
	ft_puthexa_fd((size_t)ptr, 2);
	ft_putendl(": pointer being free wasn't allocated");
	abort();
}

void		my_free(void *ptr, size_t *tab_index)
{
	t_header_memarea *past;
	t_header_memarea *current;
	t_header_memarea *next;
	t_header_memarea *second;

	if (!check_entry(ptr, tab_index))
		return ;
	current = (t_header_memarea *)(ptr - sizeof(t_header_memarea));
	if (current->bIsFree)
		abort_free(ptr);
	current->bIsFree = 1;
	past = (void *)current->previous_header;
	if (past)
	{
		if (past->bIsFree)
		{
			past->size += (current->size + sizeof(t_header_memarea));
			ft_bzero(current, sizeof(t_header_memarea));
			current = past;
			ptr = (void *)current + sizeof(t_header_memarea);
		}
	}
	if (current->size < current->total_size)
	{
		next = (t_header_memarea *)(ptr + current->size);
		if (next->bIsFree)
		{
			if (next->size < next->total_size)
			{
				second = (t_header_memarea *)((void *)next + next->size
							+ sizeof(t_header_memarea));
				second->previous_header = (size_t)current;
			}
			current->size += (next->size + sizeof(t_header_memarea));
		}
		else if (past)
		{
			next->previous_header = (size_t)current;
		}
	}
	ft_bzero(ptr, current->size);
	if (current->size == current->total_size && current->previous_header == 0)
		remove_page(current, tab_index);
}
