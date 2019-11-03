/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:23:41 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:39:14 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 4096
# define OPEN_MAX 256
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define BLACK 0x00000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF

typedef struct	s_elem
{
	int		**board;
	int		line;
	int		collum;
	void	*mlx;
	void	*win;
	int		basex;
	int		basey;
	int		lenght;
	char	*name;
	int		color;
}				t_elem;

typedef struct	s_trace
{
	int i;
	int k;
	int x;
	int y;
}				t_trace;

typedef struct	s_cor
{

	int dx;
	int sx;
	int dy;
	int sy;
	int fault;
	int value;
}				t_cor;

typedef struct		s_pos
{
	int x;
	int y;
}					t_pos;


void			program(int argc, char **argv, t_elem elem);
int				counter_x(char *str);
int				counter_y(char *str);
void			fill_board(t_elem *elem, int fd);
void			reader(char *str, t_elem *map);
void			setup_window(t_elem *win);
int				drawing(t_elem *elem);
void			trace_line(t_pos *v0, t_pos *v1, t_elem *elem);
void			gen_x_axes_mid(t_elem *e, int i, int s, t_trace *t);
void			gen_x_axes_top(t_elem *e, int i, int s, t_trace *t);
void			gen_y_axes_mid(t_elem *e, int i, int s, t_trace *t);
void			gen_y_axes_top(t_elem *e, int i, int s, t_trace *t);
int				keyboard(int keycode, t_elem *elem);
void			gen_screen(t_elem *elem);
void			ft_exit(char *error);
void			print_board(int **tab, int x, int y);
int				color(int value);
void			ft_black_screen(t_elem *elem);
void			select_axes(int value, t_elem *e, int i, t_trace *s);
void			text_window(t_elem *elem);
int				color(int value);
int				get_next_line(const int fd, char **line);

#endif
