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
// TODO: Check NULL terminated strings if necessary

int	fill_buffer(int fd, char **buff)
{
	char	*new_buff;
	int		str_len;

	if (!*buff)
	{
		*buff = malloc(BUFFER_SIZE * sizeof(char));
		if (!*buff)
			return (-1);
		return (read(fd, *buff, BUFFER_SIZE));
	}
	else if (get_line_break_pos(*buff) == -1)
	{
		str_len = ft_strlen(*buff);
		new_buff = malloc((str_len + BUFFER_SIZE) * sizeof(char));
		if (!new_buff)
			return (-1);
		ft_strlcpy(new_buff, *buff, str_len);
		free(*buff);
		*buff = new_buff;
		return (read(fd, *buff + str_len, BUFFER_SIZE));
	}
	return (1);
}

static char	*get_line_clean_buffer(char **buff, int	buff_res)
{
	int		finish;
	char	*line;
	int		buff_len;
	char	*excedent;

	(void) buff_res;
	if (**buff == '\0' && buff_res <= 0)
		return (NULL);
	buff_len = ft_strlen(*buff);
	finish = get_line_break_pos(*buff);
	if (finish == -1)
		finish = buff_len - 1;
	line = ft_substr(*buff, 0, finish + 1);
	if (!line)
		return (NULL);
	if (finish == buff_len - 1)
		*buff = NULL;
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
	int				fill_buff_res;

	fill_buff_res = fill_buffer(fd, &buff);
	if (fill_buff_res < 0 || (fill_buff_res == 0 && buff == NULL))
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = get_line_clean_buffer(&buff, fill_buff_res);
	if (!line)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	return (line);
}
