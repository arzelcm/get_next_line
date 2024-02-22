/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:17:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/20 20:24:59 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (-1);
	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

int	get_line_break_pos(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (i < ft_strlen(str) && str[i] != '\n')
		i++;
	if (i == ft_strlen(str))
		return (-1);
	else
		return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char			*result;
	int				i;
	int				strlen;
	int				final_len;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	/*if (start >= strlen)
		return (ft_strdup(""));*/
	final_len = len;
	if (final_len > strlen - start)
		final_len = strlen - start;
	result = malloc(sizeof(char) * final_len + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < len && start + i < strlen)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
