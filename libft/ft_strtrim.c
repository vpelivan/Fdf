/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:59:50 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/01 19:28:12 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*memory_alloc(size_t start, size_t end, char *str, char const *s)
{
	size_t i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while (end + 1 > start)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	str = NULL;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		str = (char *)malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	start = i;
	while (s[i])
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i > 0)
		i--;
	end = i;
	return (memory_alloc(start, end, str, s));
}
