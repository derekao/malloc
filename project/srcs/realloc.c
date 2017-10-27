/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:21:59 by semartin          #+#    #+#             */
/*   Updated: 2017/10/24 11:21:59 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	abort_realloc : Abort if the ptr has already been freed
**	----------------------------------------------------------------------------
**  realloc_next : If the next area is free merge it with the current ptr
**	----------------------------------------------------------------------------
**	realloc : realloc a ptr with size bit
*/

static void	abort_realloc(void *ptr)
{
	ft_putstr_fd("Malloc error for object : 0x", 2);
	ft_puthexa_fd((int)ptr, 2);
	ft_putendl(": pointer being reallocated wasn't allocated");
	abort();
}

static void	split_next(t_header_memarea *current, t_header_memarea *next,
						size_t size_need)
{
	t_header_memarea	*second;
	t_header_memarea	*third;

	second = (t_header_memarea *)((void *)next + size_need
				+ sizeof(t_header_memarea));
	second->size = next->size - size_need - sizeof(t_header_memarea);
	second->total_size = next->total_size - size_need
								- sizeof(t_header_memarea);
	second->previous_header = (size_t)current;
	second->bIsFree = 1;
	if (second->size < second->total_size)
	{
		third = (t_header_memarea *)((void *)second + second->size
				+ sizeof(t_header_memarea));
		third->previous_header = (size_t)second;
	}
	next->size = size_need;
}

static int	realloc_next(t_header_memarea *current, size_t size, void *ptr)
{
	t_header_memarea	*next;
	t_header_memarea	*second;
	size_t				size_need;

	size_need = size - current->size - sizeof(t_header_memarea);
	next = (t_header_memarea *)(ptr + current->size);
	if (next->bIsFree && next->size + current->size
							+ sizeof(t_header_memarea) > size)
	{
		if (next->size > size_need * 2 && next->size
					>= sizeof(t_header_memarea) + size)
			split_next(current, next, size_need);
		else if (next->size < next->total_size)
		{
			second = (t_header_memarea *)((void *)next + next->size
						+ sizeof(t_header_memarea));
			second->previous_header = (size_t)current;
		}
		current->size += (next->size + sizeof(t_header_memarea));
		ft_bzero(next, sizeof(t_header_memarea));
		return (1);
	}
	return (0);
}

void		*my_realloc(void *ptr, size_t size, size_t *tab_index)
{
	t_header_memarea	*current;
	void				*newptr;

	if (!check_entry(ptr, tab_index))
		return (malloc(size));
	current = (t_header_memarea *)(ptr - sizeof(t_header_memarea));
	if (current->bIsFree)
		abort_realloc(ptr);
	if (current->size >= size)
		return (ptr);
	if (current->size < current->total_size)
	{
		if (realloc_next(current, size, ptr))
			return (ptr);
	}
	newptr = malloc(size);
	ft_memcpy(newptr, ptr, current->size);
	free(ptr);
	return (newptr);
}
