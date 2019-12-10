/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:45:13 by cmarteau          #+#    #+#             */
/*   Updated: 2019/12/10 19:01:55 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

int	ft_search(char *buf)
{
	unsigned int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	int fd;
	int ret;
	char buf[BUFFER_SIZE + 1];
	static char bufbuf[BUFFER_SIZE + 1];
	unsigned int	i;
	
	i = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) || !ft_search(bufbuf))
	{
		buf[ret] = '\0';
		ft_strcpy(*line, buf);
	}
}

int	main()
{
	int fd;
	int ret;
	char buf[BUFFER_SIZE + 1];
	static char bufbuf[BUFFER_SIZE + 1];
	unsigned int	i;

	i = 0;
	fd = open("test.c", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() erreur");
		return (1);
	}
	while (get_next_line(fd, line) == 1)
		printf("%s", line);
	printf("%s", line);
	return (0);
}
