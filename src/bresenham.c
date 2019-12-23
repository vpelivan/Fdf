/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:45:37 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/27 15:38:07 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

static void	less_or_equal(const t_fdf *lst, t_brez *l)
{
	(*l).x = (*l).x1;
	(*l).y = (*l).y1;
	(*l).d = -(*l).length_x;
	(*l).length++;
	while ((*l).length--)
	{
		mlx_pixel_put(lst->mlx, lst->win, (*l).x, (*l).y, lst->color);
		(*l).x += (*l).dx;
		(*l).d += 2 * (*l).length_y;
		if ((*l).d > 0)
		{
			(*l).d -= 2 * (*l).length_x;
			(*l).y += (*l).dy;
		}
	}
}

static void	more(const t_fdf *lst, t_brez *l)
{
	int x;
	int y;
	int d;

	x = (*l).x1;
	y = (*l).y1;
	d = -(*l).length_y;
	(*l).length++;
	while ((*l).length--)
	{
		mlx_pixel_put(lst->mlx, lst->win, x, y, lst->color);
		y += (*l).dy;
		d += 2 * (*l).length_x;
		if (d > 0)
		{
			d -= 2 * (*l).length_y;
			x += (*l).dx;
		}
	}
}

void		line(t_elm one, t_elm two, t_fdf *lst)
{
	t_brez	l;

	l.x1 = one.x;
	l.y1 = one.y;
	l.x2 = two.x;
	l.y2 = two.y;
	l.dx = (l.x2 - l.x1 >= 0 ? 1 : -1);
	l.dy = (l.y2 - l.y1 >= 0 ? 1 : -1);
	l.length_x = ft_abs(l.x2 - l.x1);
	l.length_y = ft_abs(l.y2 - l.y1);
	l.length = ft_max(l.length_x, l.length_y);
	if (l.length == 0)
		mlx_pixel_put(lst->mlx, lst->win, l.x1, l.y1, lst->color);
	if (l.length_y <= l.length_x)
		less_or_equal(lst, &l);
	else
		more(lst, &l);
}

void		offset(t_fdf *lst, t_elm **map)
{
	int i;
	int j;

	i = 0;
	while (i < lst->m_height)
	{
		j = 0;
		while (j < lst->m_width)
		{
			map[i][j].x = map[i][j].x + lst->offset_x;
			map[i][j].y = map[i][j].y + lst->offset_y;
			j++;
		}
		i++;
	}
}
