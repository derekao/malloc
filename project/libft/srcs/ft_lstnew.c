/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semartin <semartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:12:01 by semartin          #+#    #+#             */
/*   Updated: 2014/11/07 11:47:49 by semartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	if ((list->content = (void *)content) == NULL)
		list->content_size = 0;
	else
		list->content_size = content_size;
	list->next = NULL;
	return (list);
}
