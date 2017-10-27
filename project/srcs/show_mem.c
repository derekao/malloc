/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:49:44 by semartin          #+#    #+#             */
/*   Updated: 2017/10/26 10:49:46 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void print_dump(char *ptr, size_t n)
{
	int i = 0;
	ft_putstr(BLUE);
	while (n > 0)
	{
		if (i == 32)
		{
			i = 0;
			ft_putchar('\n');
		}
		ft_putbyte(*ptr);
		ptr++;
		n--;
		i++;
	}
	ft_putchar('\n');
}

static void print_tiny(void *ptr, size_t *total_size, int b)
{
	t_header_memarea *header;

	ft_putstr("TINY : 0x");
	ft_puthexa_fd((size_t)ptr, 1);
	ft_putchar('\n');
	header = (t_header_memarea *)ptr;
	while (header)
	{
		if (!header->bIsFree)
		{
			ft_putstr(GREEN);
			*total_size += header->size;
		}
		else
			ft_putstr(RED);
		ft_putstr("0x");
		ft_puthexa_fd((size_t)header + sizeof(t_header_memarea), 1);
		ft_putstr(" - 0x");
		ft_puthexa_fd((size_t)header + sizeof(t_header_memarea)
							+ header->size, 1);
		ft_putstr(" : ");
		ft_putnbr(header->size);
		ft_putendl(" octets");
		if (!header->bIsFree && b)
			print_dump((void *)header + sizeof(t_header_memarea), header->size);
		ft_putstr(NC);
		if (header->total_size != header->size)
			header = (void *)header + sizeof(t_header_memarea) + header->size;
		else
			header = NULL;
	}
}

static void print_small(void *ptr, size_t *total_size, int b)
{
	t_header_memarea *header;

	ft_putstr("SMALL : 0x");
	ft_puthexa_fd((size_t)ptr, 1);
	ft_putchar('\n');
	header = (t_header_memarea *)ptr;
	while (header)
	{
		if (!header->bIsFree)
		{
			*total_size += header->size;
			ft_putstr(GREEN);
		}
		else
			ft_putstr(RED);
		ft_putstr("0x");
		ft_puthexa_fd((size_t)header + sizeof(t_header_memarea), 1);
		ft_putstr(" - 0x");
		ft_puthexa_fd((size_t)header + sizeof(t_header_memarea)
							+ header->size, 1);
		ft_putstr(" : ");
		ft_putnbr(header->size);
		ft_putendl(" octets");
		if (!header->bIsFree && b)
			print_dump((void *)header + sizeof(t_header_memarea), header->size);
		ft_putstr(NC);
		if (header->total_size != header->size)
			header = (void *)header + sizeof(t_header_memarea) + header->size;
		else
			header = NULL;
	}
}

static void print_large(void *ptr, size_t *total_size, int b)
{
	t_header_memarea *header;

	header = (t_header_memarea *)ptr;
	ft_putstr("LARGE : 0x");
	ft_puthexa_fd((size_t)ptr, 1);
	ft_putchar('\n');
	if (!header->bIsFree)
	{
		ft_putstr(GREEN);
		*total_size += header->size;
	}
	else
		ft_putstr(RED);
	ft_putstr("0x");
	ft_puthexa_fd((size_t)header + sizeof(t_header_memarea), 1);
	ft_putstr(" - 0x");
	ft_puthexa_fd((size_t)header + sizeof(t_header_memarea)
						+ header->size, 1);
	ft_putstr(" : ");
	ft_putnbr(header->size);
	ft_putendl(" octets");
	if (!header->bIsFree && b)
		print_dump((void *)header + sizeof(t_header_memarea), header->size);
	ft_putstr(NC);
}

void my_show_alloc_mem(size_t *tab_index, size_t *total_size, int b)
{
	int		lastindex;
	int 	i;

	lastindex = getpagesize() * MALLOC_INDEX_SIZE / sizeof(size_t) - 2;
	i = 0;
	while (i < lastindex)
	{
		if (tab_index[i + 1] == INDEX_TINY)
			print_tiny((void *)tab_index[i], total_size, b);
		else if (tab_index[i + 1] == INDEX_SMALL)
			print_small((void *)tab_index[i], total_size, b);
		else if (tab_index[i + 1] == INDEX_LARGE)
			print_large((void *)tab_index[i], total_size, b);
		i += 2;
	}
	if (tab_index[i + 1] == INDEX_NEXTPAGE)
		my_show_alloc_mem((size_t *)tab_index[i], total_size, b);
	else
	{
		ft_putstr("Total : ");
		ft_putnbr(*total_size);
		ft_putendl(" octets");
	}
}

