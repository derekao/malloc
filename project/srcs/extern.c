/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:24:55 by semartin          #+#    #+#             */
/*   Updated: 2017/10/27 14:24:57 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void show_alloc_mem()
{
	show_alloc_mem_t(0);
}

void show_alloc_mem_ex()
{
    show_alloc_mem_t(1);
}