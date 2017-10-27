/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:42:08 by semartin          #+#    #+#             */
/*   Updated: 2017/10/24 17:42:08 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

void 	show_alloc_mem_ex();

int main()
{
	int *str;
	int *str1;
	int *ptr;
	int *ptr2;
	int *str2;
	int **str3;
	int *x;

	x = malloc(5);

	str = malloc(48);
	str1 = malloc(24);
	ptr = malloc(108);
	str1 = realloc(str1, 150);
	ptr2 = malloc(12);
	str3 = malloc(841);
	str3 = malloc(21244);
//	str3 = malloc(584084);
    ft_putendl("1----------------");
	for (int i = 0; i < 1000; i++)
	{
		str3[i] = malloc(50);
	}
	ft_putendl("2----------------");
	for (int i = 0; i < 1000; i++)
	{
		free(str3[i]);
	}
	ft_putendl("3----------------");
	for (int i = 0; i < 200; i++)
	{
		str3[i] = malloc(50);
	}
	/*free(x);
	free(str);
	free(str1);
	free(str3);*/
	show_alloc_mem();
	return 0;
}