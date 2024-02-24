/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arzelcm <arzelcm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:25:32 by arzelcm           #+#    #+#             */
/*   Updated: 2024/02/24 01:39:49 by arzelcm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Canviar el header!
#include "get_next_line_bonus.h"
// TODO: Check max ints and stuff

static int	init_buffer(int fd, char **buff)
{
	int	read_res;

	read_res = 1;
	*buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buff)
		return (-1);
	read_res = read(fd, *buff, BUFFER_SIZE);
	if (read_res == 0)
		return (-1);
	if (read_res > 0)
		(*buff)[read_res] = '\0';
	return (read_res);
}

static int	fill_buffer(int fd, char **buff)
{
	char	*new_buff;
	int		str_len;
	int		read_res;

	read_res = 1;
	if (!*buff)
	{
		read_res = init_buffer(fd, buff);
		if (read_res == -1)
			return (-1);
	}
	while (get_line_break_pos(*buff) == -1 && read_res > 0)
	{
		str_len = ft_strlen(*buff);
		new_buff = malloc((str_len + BUFFER_SIZE + 1) * sizeof(char));
		if (!new_buff)
			return (-1);
		ft_strlcpy(new_buff, *buff, str_len + 1);
		free(*buff);
		*buff = new_buff;
		read_res = read(fd, *buff + str_len, BUFFER_SIZE);
		if (read_res > 0)
			(*buff)[str_len + read_res] = '\0';
	}
	return (read_res);
}

static int	clean_buffer(char **buff, int finish, int buff_len, char **line)
{
	char	*excedent;

	if (finish == buff_len - 1)
		free_buff(buff);
	else
	{
		excedent = ft_substr(*buff, finish + 1, buff_len);
		if (!excedent)
			return (free(line), 0);
		free(*buff);
		*buff = excedent;
	}
	return (1);
}

static char	*get_line_clean_buffer(char **buff, int buff_res)
{
	int		finish;
	char	*line;
	int		buff_len;
	int		clean_buffer_res;

	if (**buff == '\0' && buff_res <= 0)
		return (free_buff(buff), NULL);
	finish = get_line_break_pos(*buff);
	buff_len = ft_strlen(*buff);
	if (finish == -1 && buff_res <= 0)
		finish = buff_len - 1;
	line = ft_substr(*buff, 0, finish + 1);
	if (!line)
		return (NULL);
	clean_buffer_res = clean_buffer(buff, finish, buff_len, &line);
	if (!clean_buffer_res)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;
	int			fill_buff_res;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	fill_buff_res = fill_buffer(fd, &buff[fd]);
	if ((fill_buff_res < 0 || (fill_buff_res == 0 && *buff[fd] == '\0')))
		return (free_buff(&buff[fd]), NULL);
	line = get_line_clean_buffer(&buff[fd], fill_buff_res);
	if (!line)
		return (free_buff(&buff[fd]), NULL);
	return (line);
}
