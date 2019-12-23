/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:52:20 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/26 19:52:23 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map_coords(t_fdf *lst, int x, int y, int i)
{
	while (lst->str[i])
	{
		if (ft_isdigit(lst->str[i]) == 1 || lst->str[i] == '-')
		{
			init_map_struct(lst, x, y);
			lst->map_clean[y][x].z = ft_atoi(&lst->str[i]);
			while (ft_strchr("-0123456789", lst->str[i]) != NULL
			&& lst->str[i])
				i++;
			lst->map_clean[y][x].x += lst->dist * x;
			lst->map_clean[y][x].y = lst->dist * y;
			if (lst->str[i] == ',')
			{
				lst->map_clean[y][x].color =
				ft_atoi_base(&lst->str[i += 3], 16);
				while (ft_strchr("0123456789abcdefABCDEF", lst->str[i])
				!= NULL && lst->str[i])
					i++;
			}
			x++;
		}
		if (lst->str[i] != '\0')
			i++;
	}
}

t_elm	**mapdup(t_elm **map_src, t_elm **map_dst, t_fdf *lst)
{
	int i;
	int j;

	i = 0;
	map_dst = (t_elm **)malloc(sizeof(t_elm *) * lst->m_height);
	while (i < lst->m_height)
	{
		j = 0;
		map_dst[i] = (t_elm *)malloc(sizeof(t_elm) * lst->m_width);
		while (j < lst->m_width)
		{
			map_dst[i][j].x = map_src[i][j].x;
			map_dst[i][j].y = map_src[i][j].y;
			map_dst[i][j].z = map_src[i][j].z;
			map_dst[i][j].color = map_src[i][j].color;
			j++;
		}
		i++;
	}
	return (map_dst);
}

void	get_map(t_fdf *lst)
{
	int	i;

	i = 0;
	while (get_next_line(lst->fd, &lst->str) > 0)
	{
		if (i == 0)
			lst->map_clean = (t_elm **)malloc(sizeof(t_elm *) * lst->m_height);
		lst->map_clean[i] = (t_elm *)malloc(sizeof(t_elm) * lst->m_width);
		fill_map_coords(lst, 0, i, 0);
		free(lst->str);
		i++;
	}
	lst->map = mapdup(lst->map_clean, lst->map, lst);
}

void	iso(t_fdf *lst)
{
	int i;
	int j;

	i = 0;
	while (i < lst->m_height)
	{
		j = 0;
		while (j < lst->m_width)
		{
			lst->map[i][j].x = (int)((lst->map_clean[i][j].y
			+ lst->map_clean[i][j].x) * cos(lst->angle));
			lst->map[i][j].y = (int)((lst->map_clean[i][j].y
			- lst->map_clean[i][j].x) * sin(lst->angle)
			- (lst->map_clean[i][j].z * lst->f_height));
			lst->map[i][j].z = lst->map_clean[i][j].z * lst->f_height;
			lst->map[i][j].color = lst->map_clean[i][j].color;
			j++;
		}
		i++;
	}
}

void	side(t_fdf *lst)
{
	int i;
	int j;

	i = 0;
	while (i < lst->m_height)
	{
		j = 0;
		while (j < lst->m_width)
		{
			lst->map[i][j].x = lst->map_clean[i][j].x;
			lst->map[i][j].y = lst->map_clean[0][0].y
			- (lst->map_clean[i][j].z * lst->f_height);
			lst->map[i][j].z = lst->map_clean[i][j].z * lst->f_height;
			lst->map[i][j].color = lst->map_clean[i][j].color;
			j++;
		}
		i++;
	}
}
