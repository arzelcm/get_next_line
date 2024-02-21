/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:16:15 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/20 21:07:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// TODO: Check max ints and stuff

static char	*fill_buffer(int fd, char **buff)
{
	int		read_res;
	char	*new_buff;
	int		str_len;

	if (!*buff)
	{
		*buff = malloc(BUFFER_SIZE * sizeof(char));
		if (!*buff)
			return (NULL);
		read_res = read(fd, *buff, BUFFER_SIZE);
		if (read_res <= 0)
			return (NULL);
	}
	else if (get_line_break_pos(*buff) == -1)
	{
		str_len = ft_strlen(*buff);
		new_buff = malloc((str_len + BUFFER_SIZE) * sizeof(char));
		free(*buff);
		*buff = new_buff;
		read_res = read(fd, *buff + str_len, BUFFER_SIZE);
		if (read_res <= 0)
			return (NULL);
	}
	return (*buff);
}

static char	*get_line_clean_buffer(char **buff)
{
	int		finish;
	char	*line;
	int		buff_len;
	char	*excedent;

	finish = get_line_break_pos(*buff);
	if (finish == -1)
		return (NULL);
	line = ft_substr(*buff, 0, finish + 1);
	if (!line)
		return (NULL);
	buff_len = ft_strlen(*buff);
	if (finish == buff_len - 1)
	{
		free(*buff);
		*buff = NULL;
	}
	else
	{
		excedent = ft_substr(*buff, finish + 1, buff_len);
		if (!excedent)
			return (NULL);
		*buff = excedent;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char    *buff = NULL;
	char			*line;

	if (!fill_buffer(fd, &buff))
		return (NULL);
	line = get_line_clean_buffer(&buff);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	return (line);
}
