/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_into_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 09:29:26 by semartin          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:07 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lst_into_tab : Make a tab using a list
*/

void	**ft_lst_into_tab(t_list *lst)
{
	t_list	*tmp;
	void	**tab;
	int		i;

	tab = malloc(sizeof(tab) * (ft_lst_size(lst) + 1));
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}
