/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/07 19:24:38 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*buf2;
	char		*c;
	int			i;

	buf = cutstring1(save);
	if (buf)
	{
		save = cutstring2(save);
		return (buf);
	}
	else
	{
		buf2 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i = readandjoin(fd, buf2, save, BUFFER_SIZE);
		while (i <= 0)
		{
			if(i < 0)
				return (NULL);
			i = readandjoin(fd, buf2, save, BUFFER_SIZE);
		}
		free(buf2);
		printf("%s\n",save);
		c = cutstring1(save);
		save = cutstring2(save);
		return (c);
	}
	i = fd;
	return (NULL);
}

int	readandjoin(int fd, char *buf, char *save, size_t n)
{
	char	*c;
	int		i;

	if (read(fd, buf, n) < 0)
		return (-1);
	buf[n] = '\0';
	if (!save)
		ft_memcpy(save, buf, n);
	else
	{
		c = ft_strjoin(save, buf);
		i = ft_strlen(c);
		ft_memcpy(save, c, i + 1);
	}
	if (!cutstring1(save))
	{
		write(1, "3", 1);
		return (0);
	}
	else
		return (1);
}

char	*cutstring1(char *s)
{
	int		i;
	char	*temp;

	temp = ft_strdup(s);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			temp[i + 1] = '\0';
			return (temp);
		}
		else
			i++;
	}
	return (NULL);
}

char	*cutstring2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (&s[i + 1]);
		else
			i++;
	}
	return (s);
}

int main()
{
    int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
