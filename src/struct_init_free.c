/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:52:21 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/26 13:52:22 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_val(t_val **l, t_fdf *lst)
{
	*l = malloc(sizeof(t_val));
	(*l)->i = 0;
	(*l)->nb = 0;
	(*l)->len = (int)ft_strlen(lst->str);
	(*l)->end = (*l)->len - 1;
}

t_fdf	*get_struct(char **av)
{
	t_fdf *l;

	l = malloc(sizeof(t_fdf));
	l->map = NULL;
	l->str = NULL;
	l->mlx = NULL;
	l->win = NULL;
	l->err_msg = "unable to open a file: file does not exist or incorrect "
	"file name\n";
	l->err_msg1 = "error: map is not valid\n";
	l->fd = 0;
	l->av = av;
	l->m_width = 0;
	l->m_height = 0;
	l->f_height = 2;
	l->angle = 0.523599;
	l->dist = 30;
	l->offset_x = 0;
	l->offset_y = 0;
	l->offset_y = 600;
	l->color = 0xFFFFFF;
	l->view = 2;
	return (l);
}

void	init_map_struct(t_fdf *lst, int x, int y)
{
	lst->map_clean[y][x].x = 0;
	lst->map_clean[y][x].y = 0;
	lst->map_clean[y][x].z = 0;
	lst->map_clean[y][x].color = 0;
}

void	free_struct(t_fdf *lst)
{
	free_struct_map(lst, lst->map);
	free_struct_map(lst, lst->map_clean);
	free(lst);
}

void	free_struct_map(t_fdf *lst, t_elm **map)
{
	int i;

	i = 0;
	while (i < lst->m_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
