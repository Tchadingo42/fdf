/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:40:50 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:48:30 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reader(char *str, t_elem *elem)
{
	int		fd;


	elem->line = counter_x(str);
	elem->collum = counter_y(str);
	if (!(elem->board = (int **)malloc(sizeof(int*) * elem->line)))
		ft_exit("malloc 2 failed\n");
	fd = open(str, O_RDONLY);
	if (fd < 0 || str == NULL || !str[0])
		ft_exit("fd reader failed\n");
	fill_board(&*elem, fd);
	close(fd);
}
