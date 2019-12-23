/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:09:32 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/01 19:35:30 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_tab(char *str, int value)
{
	char	*tab;
	int		flag;
	int		tmp;
	int		size;

	size = 0;
	flag = 0;
	tmp = value;
	if (value < 0)
		flag = 1;
	while (tmp /= 10)
		size++;
	size = size + flag + 1;
	tab = (char *)malloc(sizeof(str) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = '\0';
	while (size > flag)
	{
		tab[size - 1] = str[ft_abs(value % 10)];
		size--;
		value /= 10;
	}
	return (tab);
}

char		*ft_itoa(int value)
{
	char	*str;
	char	*tab;

	str = "0123456789";
	tab = ft_create_tab(str, value);
	if (!tab)
		return (NULL);
	return (tab);
}
