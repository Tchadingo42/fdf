/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_axes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:14:41 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:40:55 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		gen_x_axes_mid(t_elem *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;

	while (t->k != e->line)
	{
		while (t->i != e->collum - 1)
		{
			e->color = color(e->board[t->k][t->i]);
			if (e->board[t->k][t->i] == e->board[t->k][t->i + 1])
			{
				p1.x = t->x + i;
				p1.y = t->y - e->board[t->k][t->i];
				p2.x = t->x + s + i;
				p2.y = t->y - e->board[t->k][t->i];
				trace_line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += s;
		i -= s;
	}
}

void		gen_x_axes_top(t_elem *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;

	while (t->k != e->line)
	{
		while (t->i != e->collum - 1)
		{
			e->color = color(e->board[t->k][t->i]);
			if (e->board[t->k][t->i] != e->board[t->k][t->i + 1])
			{
				p1.x = t->x + i;
				p1.y = t->y - e->board[t->k][t->i];
				p2.x = t->x + s + i;
				p2.y = t->y - e->board[t->k][t->i + 1];
				trace_line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += s;
		i -= s;
	}
}

void		gen_y_axes_mid(t_elem *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;

	while (t->k != e->line - 1)
	{
		while (t->i != e->collum)
		{
			e->color = color(e->board[t->k][t->i]);
			if (e->board[t->k][t->i] == e->board[t->k + 1][t->i])
			{
				p1.x = t->x + i;
				p1.y = t->y - e->board[t->k][t->i];
				p2.x = t->x + i - s;
				p2.y = t->y + s - e->board[t->k][t->i];
				trace_line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += s;
		i -= s;
	}
}

void		gen_y_axes_top(t_elem *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;

	while (t->k != e->line - 1)
	{
		while (t->i != e->collum)
		{
			e->color = color(e->board[t->k][t->i]);
			if (e->board[t->k][t->i] != e->board[t->k + 1][t->i])
			{
				p1.x = t->x + i;
				p1.y = t->y - e->board[t->k][t->i];
				p2.x = t->x + i - s;
				p2.y = t->y + s - e->board[t->k + 1][t->i];
				trace_line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += s;
		i -= s;
	}
}
