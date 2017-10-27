/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:33:14 by semartin          #+#    #+#             */
/*   Updated: 2017/10/17 14:33:16 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H

# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <errno.h>

# include "libft.h"

# define MALLOC_INDEX_SIZE 8

# define MALLOC_TINY 16
# define MALLOC_SMALL 256
# define MALLOC_LARGE 4096

# define MALLOC_TINY_PAGES 4
# define MALLOC_SMALL_PAGES 16

# define INDEX_TINY 1
# define INDEX_SMALL 2
# define INDEX_LARGE 4
# define INDEX_NEXTPAGE 8
# define INDEX_FREEDZONE 16

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define NC "\033[0m"

typedef struct s_header_memarea
{
    size_t  size;
    size_t  total_size;
    size_t  previous_header;
    size_t     bIsFree;
}               t_header_memarea;

/*
** Malloc Memory Index
*/

void add_page_tab(size_t addr, int index, size_t *tab_index);
void *get_page_from_index(int index, size_t size, size_t *tab);
void		remove_page(void *current, size_t *tab);

/*
** Extern Function
*/

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem_t(int i);
void *calloc(size_t nmemb, size_t size);

/*
** extern.c
*/

void show_alloc_mem();
void show_alloc_mem_ex();

/*
** malloc_tiny.c
*/

void *ft_malloc_tiny(size_t size, size_t *tab_index);
void *getcurrentpage(size_t size, int page_index, size_t *tab_index);

/*
** malloc_small.c
*/

void *ft_malloc_small(size_t size, size_t *tab_index);

/*
** malloc_large.c
*/

void *ft_malloc_large(size_t size, size_t *tab_index);

/*
**  free.c
*/

void *my_realloc(void *ptr, size_t size, size_t *tab_index);
void my_free(void *ptr, size_t *tab_index);
int check_entry(void *ptr, size_t *tmp);

/*
**  show_mem.c
*/

void my_show_alloc_mem(size_t *tab_index, size_t *total_size, int i);
		
#endif
