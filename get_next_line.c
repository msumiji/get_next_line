/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/05 20:09:49 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*c;
	int			*i;

	buf = cutstring1(save);
	if (buf)
	{
		save = cutstring2(save);
		return (buf);
	}
	else
	{
		buf = malloc(BUFFER_SIZE);
		while (readandjoin(fd, buf, BUFFER_SIZE, i) < 0)
		{
			if (*i < 0)
				return (NULL);
		}
		free(buf);
		c = cutstring1(save);
		save = cutstring2(save);
		return (c);
	}
}

int	readandjoin(int fd, char *buf, size_t n, int *i)
{
	char		*c;
	static char	*save;

	*i = 0;
	if (read(fd, buf, n) < 0)
		*i = -1;
	save = ft_strjoin(save, buf);
	if (!cutstring1(save))
		return (0);
}

char	*cutstring1(const char *s)
{
	int		i;
	char	*temp;

	temp = ft_strdup(s);
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
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (&s[i + 1]);
		else
			i++;
	}
	return (s);
}
