/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:14:34 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/20 20:56:07 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int	ft_strlen(char *s);

int		get_line_break_pos(char *str);

char	*ft_substr(char *s, int start, int len);

#endif
