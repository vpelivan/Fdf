/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:35:45 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/19 14:36:01 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

static int	convert_and_check_nb(char c, int base)
{
	int		result;

	if (c >= '0' && c <= '9')
		result = c - 48;
	else if (c >= 'a' && c <= 'z')
		result = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		result = c - 65 + 10;
	else
		result = -1;
	if (result < base && result != -1)
		return (result);
	else
		return (-1);
}

static int	length_number(char *str, int base)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (convert_and_check_nb(str[length], base) == -1)
			break ;
		length++;
	}
	return (length);
}

int			ft_atoi_base(char *nb, int base)
{
	int		result;
	int		length;
	int		i;

	i = 0;
	if (base == 10)
		return (ft_atoi(nb));
	while (nb[i] == ' ' || nb[i] == '\t' || nb[i] == '\n'
	|| nb[i] == '\v' || nb[i] == '\r' || nb[i] == '\f')
		i++;
	result = 0;
	length = length_number(nb, base) - 1;
	while (nb[i] && length >= 0 && convert_and_check_nb(nb[i], base) != -1)
	{
		result += convert_and_check_nb(nb[i], base) * ft_power(base, length);
		i++;
		length--;
	}
	return (result);
}
