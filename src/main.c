/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:33:28 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/13 19:33:30 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_fdf *lst)
{
	(key == 53) ? key_quit(lst) : 0;
	(key == 18 || key == 19 || key == 20) ? key_view(key, lst) : 0;
	(key == 123 || key == 124 || key == 125 || key == 126) ?
	key_move(key, lst) : 0;
	(key == 12 || key == 13 || key == 14 || key == 15) ?
	key_colors(key, lst) : 0;
	(key == 24 || key == 27 || key == 30 || key == 33) ?
	key_zoom_height(key, lst) : 0;
	return (0);
}

void	render(t_fdf *lst, t_elm **map)
{
	int x;
	int y;

	y = 0;
	while (y < lst->m_height)
	{
		x = 0;
		while (x < lst->m_width)
		{
			if (x + 1 != lst->m_width)
				line(map[y][x], map[y][x + 1], lst);
			if (y + 1 != lst->m_height)
				line(map[y][x], map[y + 1][x], lst);
			x++;
		}
		y++;
	}
}

void	open_in_window(t_fdf *lst)
{
	lst->mlx = mlx_init();
	lst->win = mlx_new_window(lst->mlx, 1900, 1200, "fdf");
	render(lst, lst->map);
	mlx_key_hook(lst->win, key_press, lst);
	mlx_loop(lst->mlx);
}

int		validate_and_proceed(t_fdf *lst)
{
	if (validate_map(lst->fd, lst) == 0)
	{
		close(lst->fd);
		ft_putstr(lst->err_msg1);
		return (1);
	}
	else
	{
		close(lst->fd);
		lst->fd = open(lst->av[1], O_RDONLY);
		if (lst->fd < 0 || (read(lst->fd, NULL, 0) < 0))
		{
			ft_putstr(lst->err_msg);
			return (1);
		}
		get_map(lst);
		close(lst->fd);
		lst->offset_x = 0 - ((lst->m_width * lst->dist) / 2) + 950;
		lst->offset_y = 0 - ((lst->m_height * lst->dist) / 2) + 600;
		iso(lst);
		offset(lst, lst->map);
		open_in_window(lst);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	*lst;

	if (ac == 2)
	{
		lst = get_struct(av);
		lst->fd = open(lst->av[1], O_RDONLY);
		if (lst->fd < 0 || (read(lst->fd, NULL, 0) < 0))
		{
			ft_putstr(lst->err_msg);
			return (1);
		}
		if (validate_and_proceed(lst) == 1)
			return (1);
	}
	else
	{
		ft_putstr("usage: ./fdf map_file\n");
		return (1);
	}
	return (0);
}
