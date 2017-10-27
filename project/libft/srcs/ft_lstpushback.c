/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 15:27:58 by semartin          #+#    #+#             */
/*   Updated: 2016/02/09 14:38:44 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **alstm, t_list *new)
{
	t_list *tmp;

	if (*alstm == NULL)
	{
		return (new);
	}
	else
	{
		tmp = *alstm;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	tmp->next = new;
	return (*alstm);
}
