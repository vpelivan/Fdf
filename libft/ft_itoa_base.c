/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:19:11 by vpelivan          #+#    #+#             */
/*   Updated: 2019/01/28 12:13:07 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_tab(char *str, int size, int value, int base)
{
	char	*tab;
	int		flag;
	int		tmp;

	flag = 0;
	tmp = value;
	if (base == 10 && value < 0)
		flag = 1;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	tab = (char *)malloc(sizeof(str) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = '\0';
	while (size > flag)
	{
		tab[size - 1] = str[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (tab);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*tab;
	int		size;

	size = 0;
	str = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	tab = ft_create_tab(str, size, value, base);
	if (!tab)
		return (NULL);
	return (tab);
}
