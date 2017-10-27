#include "malloc.h"


int		main(void)
{
	void *ptr;

	ptr = malloc(1024);
	ptr = malloc(1024 * 32);
	ptr = malloc(1024 * 1024);
	ptr = malloc(1024 * 1024 * 16);
	ptr = malloc(1024 * 1024 * 128);
	ft_putstr("\n---------show_alloc_mem()------------\n");
	show_alloc_mem();
	ft_putstr("\n---------show_alloc_mem_ex()---------\n");
	show_alloc_mem_ex();
	return (0);
}
