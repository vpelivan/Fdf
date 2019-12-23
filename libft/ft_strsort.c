/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:50:24 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/05 14:01:10 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsort(char *src)
{
	size_t i;

	i = 0;
	if (!src)
		return (NULL);
	if (ft_strlen(src) == 1)
		return (src);
	while (src[i + 1] != '\0')
	{
		if (src[i] > src[i + 1])
		{
			ft_swap(&src[i], &src[i + 1]);
			i = 0;
		}
		i++;
	}
	return (src);
}
