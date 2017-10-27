/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:05:08 by semartin          #+#    #+#             */
/*   Updated: 2017/10/17 16:05:08 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "malloc_index.h"

/*
**	malloc : Return a ptr with an area with size bit allocated
*/

void	*malloc(size_t size)
{
	//show_alloc_mem();
	if (g_malloc_index == NULL)
	{
		g_malloc_index = mmap(0, getpagesize() * MALLOC_INDEX_SIZE,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	}
	if (size == 0)
	{
		errno = ENOMEM;
		return (NULL);
	}
	else if (size < MALLOC_SMALL)
	{
		return (ft_malloc_tiny(size, g_malloc_index));
	}
	else if (size < MALLOC_LARGE)
	{
		return (ft_malloc_small(size, g_malloc_index));
	}
	else
	{
		return (ft_malloc_large(size, g_malloc_index));
	}
}

void	free(void *ptr)
{
	if (g_malloc_index == NULL)
	{
		g_malloc_index = mmap(0, getpagesize() * MALLOC_INDEX_SIZE,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	}
	my_free(ptr, g_malloc_index);
}

void	*realloc(void *ptr, size_t size)
{
	if (g_malloc_index == NULL)
	{
		g_malloc_index = mmap(0, getpagesize() * MALLOC_INDEX_SIZE,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	}
	return (my_realloc(ptr, size, g_malloc_index));
}

void show_alloc_mem_t(int i)
{
	size_t total_size;

	if (g_malloc_index == NULL)
	{
		g_malloc_index = mmap(0, getpagesize() * MALLOC_INDEX_SIZE,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	}
	total_size = 0;
	my_show_alloc_mem(g_malloc_index, &total_size, i);
}

void *calloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (g_malloc_index == NULL)
	{
		g_malloc_index = mmap(0, getpagesize() * MALLOC_INDEX_SIZE,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	}
	if (nmemb * size == 0)
		return NULL;
	ptr = malloc(nmemb * size);
	ft_bzero(ptr, nmemb * size);
	return ptr;
}