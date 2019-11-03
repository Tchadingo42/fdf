/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:42:27 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 18:57:46 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			program(int argc, char **argv, t_elem elem)
{
	if (argc == 2)
	{
		reader(argv[1], &elem);
		print_board(elem.board, elem.line, elem.collum);
		elem.name = argv[1];
		elem.basex = 10;
		elem.basey = 10;
		elem.lenght = 4;
		setup_window(&elem);
	}
	else
		ft_exit("Invalid argument\n");
}
