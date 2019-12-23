/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:06:14 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/08 14:48:28 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_len(char const *s, char c, size_t *i)
{
	size_t len;

	len = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		*i += 1;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	l = 0;
	if (!s)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (l < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(str[j] = ft_strsub(s, (unsigned int)i, (ft_w_len(s, c, &i)))))
			return (NULL);
		j++;
		l++;
	}
	str[j] = 0;
	return (str);
}
