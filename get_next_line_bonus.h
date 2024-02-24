/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arzelcm <arzelcm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:25:16 by arzelcm           #+#    #+#             */
/*   Updated: 2024/02/24 01:38:31 by arzelcm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Canviar el header!
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);

int		ft_strlen(char *s);

int		get_line_break_pos(char *str);

char	*ft_substr(char *s, int start, int len);

int		ft_strlcpy(char *dst, char *src, int dstsize);

void	free_buff(char **buff);

#endif
