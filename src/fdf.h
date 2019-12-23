/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:59:34 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/27 16:34:46 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define T1 (lst->str[l->i] == '\t' || lst->str[l->i] == '\v')
# define T2 (lst->str[l->i] == '\r' )
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_elm
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_elm;

typedef struct	s_rbes
{
	int			x;
	int			y;
	int			d;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			length_x;
	int			length_y;
	int			length;
}				t_brez;

typedef	struct	s_val
{
	int			i;
	int			nb;
	int			len;
	int			end;
}				t_val;

typedef struct	s_fdf
{
	char		*str;
	char		*err_msg;
	char		*err_msg1;
	int			m_width;
	int			m_height;
	int			f_height;
	double		angle;
	t_elm		**map_clean;
	t_elm		**map;
	void		*mlx;
	void		*win;
	int			dist;
	int			offset_x;
	int			offset_y;
	int			color;
	char		**av;
	int			fd;
	int			view;
	t_val		*l;
}				t_fdf;

void			init_val(t_val **l, t_fdf *lst);
void			init_map_struct(t_fdf *lst, int x, int y);
t_fdf			*get_struct(char **av);
int				validate_map(int fd, t_fdf *lst);
void			line(t_elm one, t_elm two, t_fdf *lst);
void			get_map(t_fdf *lst);
void			iso(t_fdf *lst);
void			side(t_fdf *lst);
void			open_in_window(t_fdf *lst);
void			render(t_fdf *lst, t_elm **map);
void			offset(t_fdf *lst, t_elm **map);
t_elm			**mapdup(t_elm **map_src, t_elm **map_dst, t_fdf *lst);
void			free_struct(t_fdf *lst);
void			free_struct_map(t_fdf *lst, t_elm **map);
int				key_press(int key, t_fdf *lst);
int				key_quit(t_fdf *lst);
void			key_view(int key, t_fdf *lst);
void			key_move(int key, t_fdf *lst);
void			key_zoom_height(int key, t_fdf *lst);
void			key_colors(int key, t_fdf *lst);
int				validate_and_proceed(t_fdf *lst);

#endif
