/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:16:15 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/22 19:13:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// TODO: Check max ints and stuff
// TODO: Check NULL terminated strings if necessary
//
//
// TODO: Remove below
#include <stdio.h>

int	fill_buffer(int fd, char **buff)
{
	char	*new_buff;
	int		str_len;
	int		read_res;

	if (!*buff)
	{
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
	else if (get_line_break_pos(*buff) == -1)
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
		return (read_res);
	}
	return (1);
}

static char	*get_line_clean_buffer(char **buff, int buff_res, int fd)
{
	int		finish;
	char	*line;
	int		buff_len;
	char	*excedent;

	if (**buff == '\0' && buff_res <= 0)
	{
		free(*buff);
		*buff = NULL;
		return (NULL);
	}
	finish = get_line_break_pos(*buff);
	while (finish == -1 && buff_res > 0)
	{
		buff_res = fill_buffer(fd, buff);
		finish = get_line_break_pos(*buff);
		if (buff_res == -1)
			return (NULL);
	}
	buff_len = ft_strlen(*buff);
	if (finish == -1 && buff_res <= 0)
		finish = buff_len - 1;
	line = ft_substr(*buff, 0, finish + 1);
	if (!line)
		return (NULL);
	if (finish == buff_len - 1)
	{
		free(*buff);
		*buff = NULL;
	}
	else
	{
		excedent = ft_substr(*buff, finish + 1, buff_len);
		if (!excedent)
		{
			free(line);
			return (NULL);
		}
		free(*buff);
		*buff = excedent;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buff = NULL;
	char			*line;
	int				fill_buff_res;

	fill_buff_res = fill_buffer(fd, &buff);
	if ((fill_buff_res < 0 || (fill_buff_res == 0 && *buff == '\0')))
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = get_line_clean_buffer(&buff, fill_buff_res, fd);
	if (!line)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	return (line);
}
