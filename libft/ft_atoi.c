/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:28:15 by vpelivan          #+#    #+#             */
/*   Updated: 2018/10/31 15:36:33 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	a;
	int					b;

	i = 0;
	a = 0;
	b = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		b = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (a > 922337203685477580U && b == 1)
			return (-1);
		else if (a > 922337203685477580U && b == -1)
			return (0);
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(a * b));
}
