/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:58:45 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/01 15:31:50 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	while (dst[j] && j < dstsize)
		j++;
	while (src[i] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	return (j + len);
}
