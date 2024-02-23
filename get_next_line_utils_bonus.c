#include "get_next_line_bonus.h"


int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
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
	int	str_len;

	if (!str)
		return (-1);
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len && str[i] != '\n')
		i++;
	if (i == str_len)
		return (-1);
	else
		return (i);
}

static char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
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
	if (start >= strlen)
		return (ft_strdup(""));
	final_len = len;
	if (final_len > strlen - start)
		final_len = strlen - start;
	result = malloc(sizeof(char) * (final_len + 1));
	if (!result)
		return (NULL);
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
