/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:30:27 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/08 14:40:08 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	if (!content)
	{
		l->content_size = 0;
		l->content = NULL;
	}
	else
	{
		l->content = malloc(sizeof(content_size));
		if (!l->content)
			return (NULL);
		l->content = ft_memcpy(l->content, (void *)content, content_size);
		l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}
