/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_unassigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 10:04:42 by semartin          #+#    #+#             */
/*   Updated: 2015/09/06 09:47:51 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lst_unassigned : unassigned the lst (but don't free the content)
*/

void	ft_lst_unassigned(t_list *lst)
{
	t_list	*tmp;
	t_list	*torm;

	tmp = lst;
	while (tmp)
	{
		torm = tmp;
		tmp = tmp->next;
		torm = NULL;
	}
}
