/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_set_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:50:16 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/26 13:50:21 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_quit(t_fdf *lst)
{
	free_struct(lst);
	exit(1);
}

void	key_view(int key, t_fdf *lst)
{
	free_struct_map(lst, lst->map);
	mlx_clear_window(lst->mlx, lst->win);
	lst->map = mapdup(lst->map_clean, lst->map, lst);
	if (key == 18)
	{
		lst->offset_x = 0 - ((lst->m_width * lst->dist) / 2) + 950;
		lst->offset_y = 0 - ((lst->m_height * lst->dist) / 2) + 600;
		lst->view = 1;
	}
	if (key == 19)
	{
		iso(lst);
		lst->offset_x = 0 - ((lst->m_width * lst->dist) / 2) + 950;
		lst->offset_y = 0 - ((lst->m_height * lst->dist) / 2) + 600;
		lst->view = 2;
	}
	if (key == 20)
	{
		side(lst);
		lst->offset_x = 0 - ((lst->m_width * lst->dist) / 2) + 950;
		lst->offset_y = 0 - ((lst->m_height * lst->dist) / 2) + 600;
		lst->view = 3;
	}
	offset(lst, lst->map);
	render(lst, lst->map);
}

void	key_move(int key, t_fdf *lst)
{
	free_struct_map(lst, lst->map);
	mlx_clear_window(lst->mlx, lst->win);
	lst->map = mapdup(lst->map_clean, lst->map, lst);
	if (lst->view == 2)
		iso(lst);
	if (lst->view == 3)
		side(lst);
	if (key == 126)
		lst->offset_y -= 30;
	if (key == 125)
		lst->offset_y += 30;
	if (key == 124)
		lst->offset_x += 30;
	if (key == 123)
		lst->offset_x -= 30;
	offset(lst, lst->map);
	render(lst, lst->map);
}

void	key_colors(int key, t_fdf *lst)
{
	mlx_clear_window(lst->mlx, lst->win);
	if (key == 12)
		lst->color = 0x00FF00;
	if (key == 13)
		lst->color = 0xFF0000;
	if (key == 14)
		lst->color = 0xFFFF00;
	if (key == 15)
		lst->color = 0xFFFFFF;
	render(lst, lst->map);
}

void	key_zoom_height(int key, t_fdf *lst)
{
	free_struct_map(lst, lst->map);
	free_struct_map(lst, lst->map_clean);
	mlx_clear_window(lst->mlx, lst->win);
	if (key == 27)
	{
		if (lst->dist > 2)
			lst->dist -= 2;
	}
	if (key == 24)
		lst->dist += 2;
	if (key == 33)
		lst->f_height -= 10;
	if (key == 30)
		lst->f_height += 10;
	lst->fd = open(lst->av[1], O_RDONLY);
	get_map(lst);
	close(lst->fd);
	if (lst->view == 2)
		iso(lst);
	if (lst->view == 3)
		side(lst);
	offset(lst, lst->map);
	render(lst, lst->map);
}
