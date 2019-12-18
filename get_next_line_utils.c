/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 00:03:56 by cmarteau          #+#    #+#             */
/*   Updated: 2019/12/18 21:03:21 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*memory;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(memory = malloc(2)))
			return (0);
		memory[0] = 0;
		free(s);
		s = 0;
		return (memory);
	}
	if (!(memory = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len-- > 0)
	{
		memory[i] = s[i + start];
		i++;
	}
	memory[i] = '\0';
	if (start != 0)
	{
		free(s);
		s = 0;
	}
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
