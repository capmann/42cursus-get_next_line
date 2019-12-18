/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:45:13 by cmarteau          #+#    #+#             */
/*   Updated: 2019/12/18 20:58:27 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_search(char *s)
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
	s1 = 0;
	return (mem);
}

int		get_next_line(int fd, char **line)
{
	static char *tmp;
	int			ret;
	int			len;
	int			i;
	char		buf[BUFFER_SIZE + 1];

	ret = 1;
	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	while (((i = ft_search(tmp)) < 0) && (ret))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		tmp = ft_strjoin(tmp, buf);
	}
	len = ft_strlen(tmp);
	if (i < 0)
		i = len;
	*line = ft_substr(tmp, 0, i);
	tmp = ft_substr(tmp, i + 1, len - i - 1);
	if (ret == 0)
	{	
		free(tmp);
		tmp = 0;
		return (0);
	}
	else if (*line)
		return (1);
	return (-1);
}
