/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:14:07 by chbelan           #+#    #+#             */
/*   Updated: 2019/11/03 16:20:13 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char			*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char			*dest;

	dest = NULL;
	if (s1 && s2)
	{
		dest = ft_strnew(ft_strlen(s1) + size);
		if (dest)
		{
			ft_strcpy(dest, s1);
			ft_strncat(dest, s2, size);
		}
	}
	return (dest);
}

static int			ft_words_size(char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

static void			ft_strcpy_safe(char *dest, char *src)
{
	size_t			i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i])
	{
		dest[i] = 0;
		i++;
	}
}

static int			ft_fill(char *buf, char *line, int size)
{
	if (!line[0] && buf == NULL)
		buf[0] = 0;
	else
		ft_strcpy_safe(buf, &(buf[size + 1]));
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		buf[OPEN_MAX][BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	int				words_size;

	ret = 1;
	if (!line || fd < 0 || fd > OPEN_MAX)
		return (-1);
	*line = ft_strnew(1);
	while (ret >= 1)
	{
		if (buf[fd][0] == 0)
			ret = read(fd, &buf[fd], BUFF_SIZE);
		if (ret <= -1)
			return (ret);
		words_size = ft_words_size(buf[fd]);
		tmp = *line;
		*line = ft_strnjoin(tmp, buf[fd], words_size);
		free(tmp);
		if (buf[fd][words_size] == '\n' || (!buf[fd][0] && *line[0]))
			return (ft_fill(buf[fd], *line, words_size));
		ft_strclr((char *)&buf[fd]);
	}
	return (0);
}
