/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:51:33 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/01 11:59:07 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	j = len;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (j-- > 0)
			s1[j] = s2[j];
	}
	else
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return ((void *)s1);
}
