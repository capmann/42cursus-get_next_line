/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:45:13 by cmarteau          #+#    #+#             */
/*   Updated: 2019/12/12 19:05:21 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (j);
}

char	*ft_strdup(const char *s1)
{
	char			*memory;
	unsigned int	i;
	unsigned int	len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	if (!(memory = malloc(sizeof(char) * (len_s1 + 1))))
		return (0);
	while (s1[i])
	{
		memory[i] = s1[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;
	unsigned int len_src;
	unsigned int len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0 || len_dst >= dstsize)
		return (len_src + dstsize);
	while (dst[i])
		i++;
	while (src[j] && j < dstsize - len_dst - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_src + len_dst);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	while (s[i] != d && s[i])
		i++;
	if (s[i] == 0 && d != 0)
		return (0);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*mem;
	unsigned int	len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(mem = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(mem, s1, (ft_strlen(mem) + ft_strlen(s1) + 1));
	ft_strlcat(mem, s2, (ft_strlen(mem) + ft_strlen(s2) + 1));
	return (mem);
}

char	*read_line(int fd, char *buf, char **line)
{
	char *tmp;
	int ret;
	
	ret = 1;
	buf = NULL;
	while (!(ft_strchr(buf, '\n')) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free (tmp);
	}
	free (buf);
	return (*line);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buf;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!read_line(fd, buf, &tmp))
		return (-1);
	if (*line)
		tmp = ft_strdup(*line)
}

