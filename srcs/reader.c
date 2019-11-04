/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:27:17 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:34:09 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			counter_x(char *str)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || str == NULL || !str[0])
		ft_exit("fd x failed\n");
	while (get_next_line(fd, &line) == 1)
	{
		x++;
		free(line);
	}
	free(line);
	close(fd);
	return (x);
}

int			counter_y(char *str) // ONE MORE LEAKS HERE
{
	char	**array = NULL;
	char	*line;
	int		y;
	int		fd;


	y = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || str == NULL || !str[0])
		ft_exit("fd y failed \n");


	if (!(get_next_line(fd, &line) == 1))
		ft_exit("gnl y failed\n");

	array = ft_strsplit(line, ' ');


	free(line);

	while (get_next_line(fd, &line) == 1)
		free(line);
	free(line);
	while (array[y])
		free(array[y++]);
	free(array);
	close(fd);

	return (y);
}

void		fill_board(t_elem *elem, int fd)
{
	char	**array;
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i != elem->line)
	{
		j = 0;
		if (!(get_next_line(fd, &line) == 1))
			exit(-1);
		array = ft_strsplit(line, ' ');
		while (array[j])
			j++;
		if (!(elem->board[i] = (int *)malloc(sizeof(int) * elem->collum)))
			ft_exit("malloc 1 failed\n");
		j = 0;
		while (array[j])
		{
			elem->board[i][j] = ft_atoi(array[j]);
			j++;
		}
		j = 0;
		while (array[j])
			free(array[j++]);
		free(array);
		free(line);
		i++;
	}
}
