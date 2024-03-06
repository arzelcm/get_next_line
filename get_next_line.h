/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:14:34 by arcanava          #+#    #+#             */
/*   Updated: 2024/03/06 11:13:27 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);

int		ft_strlen(char *s);

int		line_break_pos(char *str);

char	*ft_substr(char *s, int start, int len);

int		ft_strlcpy(char *dst, char *src, int dstsize);

void	free_buffer(char **buff);

#endif
