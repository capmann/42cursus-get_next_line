/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:45:13 by cmarteau          #+#    #+#             */
/*   Updated: 2019/12/14 22:53:43 by cmarteau         ###   ########.fr       */
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
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*memory;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		/*if (!(memory = malloc(1)))
			return (0);
		memory[0] = 0;*/
		return (NULL);
	}
	if (!(memory = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len-- > 0)
	{
		memory[i] = s[i + start];
		i++;
	}
	memory[i] = '\0';
	return (memory);
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

int	ft_search(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*mem;
	unsigned int	len;

	if (!s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
	{
		if (!(mem = malloc(sizeof(char) * (ft_strlen(s2) + 1))))
			return (0);
		ft_strlcpy(mem, s2, (ft_strlen(s2) + 1));
	}
	else
	{
		if (!(mem = malloc(sizeof(char) * (len + 1))))
			return (0);
		ft_strlcpy(mem, s1, (ft_strlen(mem) + ft_strlen(s1) + 1));
		ft_strlcat(mem, s2, (ft_strlen(mem) + ft_strlen(s2) + 1));
	}
	free(s1);
	return (mem);
}

int	get_next_line(int fd, char **line)
{
	static char *tmp;
	int ret;
	int	len;
	int	i;
	char buf[BUFFER_SIZE + 1];
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (((i = ft_search(tmp)) < 0) && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = 0;
		tmp = ft_strjoin(tmp, buf);
	}	
	len = ft_strlen(tmp);
	*line  = ft_substr(tmp, 0, i);
	tmp = ft_substr(tmp, i + 1, len - i - 1);
	if (ret == 0)
		return (0);
	else if (*line)
		return (1);
	return (-1);
}

