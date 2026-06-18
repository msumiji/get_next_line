/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/18 16:48:40 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = readandsave(fd, save);
	buf = beforenewline(save);
	if (!buf)
	{
		free(save);
		return (NULL);
	}
	if (findnewline(save) < 0)
		save = change_null(save);
	else
	{
		save = afternewline(save);
		if (!save)
		{
			free(buf);
			return (NULL);
		}
	}
	return (buf);
}

char	*readandsave(int fd, char *save)
{
	char	*buf2;
	int		n;

	buf2 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf2)
	{
		free(save);
		return (NULL);
	}
	while (findnewline(save) < 0)
	{
		n = (int)read(fd, buf2, BUFFER_SIZE);
		if (n <= 0)
		{
			free(buf2);
			if (n == 0)
				return (save);
			free(save);
			return (NULL);
		}
		buf2[n] = '\0';
		save = ft_strjoin(save, buf2);
	}
	free(buf2);
	return (save);
}

int	findnewline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		else
			i++;
	}
	return (-1);
}

char	*afternewline(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*c;

	if (!s)
		return (NULL);
	i = findnewline(s);
	len = ft_strlen(s);
	c = malloc(sizeof(char) * (len - i));
	if (!c)
	{
		free(s);
		return (NULL);
	}
	j = 0;
	while (j < len - i)
	{
		c[j] = s[i + j + 1];
		j++;
	}
	free(s);
	return (c);
}

char	*beforenewline(char *s)
{
	int		i;
	int		n;
	char	*temp;

	n = findnewline(s);
	if (n < 0)
		return (ft_strdup((const char *)s));
	temp = malloc(sizeof(char) * (n + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int main(void)
{
    int   fd;
    char  *s;
	int	i;

	i = 0;
    fd = open("test2.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    while (1)
    {
		s = get_next_line(fd);
		if(!s)
			return (0);
        printf("%s", s);
		free(s);
		i++;
    }
    close(fd);
    return 0;
}
//int main(void) {
//    char *line;

//    printf("文字を入力してください（Ctrl+D で終了）:\n");

//    while ((line = get_next_line(0)) != NULL) {
//        printf("%s", line);
//        free(line);
//    }
//    return 0;
//}
