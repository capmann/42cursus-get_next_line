/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:29:12 by cmarteau          #+#    #+#             */
/*   Updated: 2019/12/15 17:59:16 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int get_next_line(int fd, char **line);

int main(int ac, char **ag)
{
	int 	fd;
	int		i;
	char	*line;

	fd = 0;
	if (ac >= 2)
		fd = open(ag[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d -> %s\n", i, line);
		free(line);
	}
	printf("%d -> %s\n", i, line);
	free(line);
	//printf("%d -> %s\n", get_next_line(fd, &line), line);
	system("leaks a.out");
}
