/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:39:11 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/22 14:39:19 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	coma(t_fdf *lst, t_val *l)
{
	if (l->i == 0 || ft_strnstr(&lst->str[l->i + 1], "0x", 2) == 0
		|| ft_isdigit(lst->str[l->i - 1]) == 0)
		return (0);
	l->i += 3;
	l->len -= 3;
	while (ft_strchr("abcdefABCDEF0123456789", lst->str[l->i]) != NULL
	&& lst->str[l->i])
	{
		l->i++;
		l->len--;
	}
	if (lst->str[l->i] != ' ' && lst->str[l->i] != '\0' && !(T1 || T2))
		return (0);
	return (1);
}

static int	minus(t_fdf *lst, t_val *l)
{
	if (lst->str[l->i] == '-')
	{
		if ((l->i != 0 && lst->str[l->i - 1] != ' ')
		|| (ft_isdigit(lst->str[l->i + 1]) != 1))
			return (0);
		l->i++;
		while (ft_isdigit(lst->str[l->i]) == 1 && lst->str[l->i])
			l->i++;
		if (lst->str[l->i] != ' ' && lst->str[l->i] != ',')
			return (0);
		l->nb++;
	}
	return (1);
}

static int	digit(t_fdf *lst, t_val *l)
{
	l->nb++;
	while (ft_strchr("0123456789", lst->str[l->i]) != NULL
	&& lst->str[l->i])
		l->i++;
	if (lst->str[l->i] != ' ' && lst->str[l->i] != ','
		&& lst->str[l->i] != '\0' && !(T1 || T2))
		return (0);
	return (1);
}

static int	val_string(t_fdf *lst, int *prev_nb, t_val *l)
{
	if (!l->len)
		return (0);
	while (lst->str[l->i])
	{
		if (ft_strchr(" ,-xabcdefABCDEF0123456789\t\v\f\r", lst->str[l->i])
		== 0 || ft_strchr(" -0123456789\t\v\f\r", lst->str[0]) == 0
		|| ft_strchr(" abcdefABCDEF0123456789\t\v\f\r", lst->str[l->end]) == 0)
			return (0);
		else if (lst->str[l->i] == '-' && minus(lst, lst->l) == 0)
			return (0);
		else if (lst->str[l->i] == ',' && coma(lst, lst->l) == 0)
			return (0);
		else if (lst->str[l->i] == ' ' || T1 || T2)
			l->i++;
		else if (ft_isdigit(lst->str[l->i]) == 1 && digit(lst, lst->l) == 0)
			return (0);
	}
	if (l->nb != *prev_nb && lst->m_height)
		return (0);
	*prev_nb = l->nb;
	lst->m_width = l->nb;
	return (1);
}

int			validate_map(int fd, t_fdf *lst)
{
	int prev_nb;
	int empty_file;

	prev_nb = 0;
	empty_file = 0;
	if ((read(fd, NULL, 0) < 0))
		return (0);
	while (get_next_line(fd, &lst->str) > 0)
	{
		init_val(&lst->l, lst);
		if (!val_string(lst, &prev_nb, lst->l))
			return (0);
		free(lst->l);
		free(lst->str);
		lst->m_height++;
		empty_file++;
	}
	close(fd);
	if (empty_file)
		return (1);
	return (0);
}
