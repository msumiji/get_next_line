/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/14 19:59:22 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = readandsave(fd, save);
	if (!save)
		return (NULL);
	buf = cutstring3(save);
	if (cutstring1(save) < 0)
		save = NULL;
	else
	{
		tmp = save;
		save = cutstring2(save);
		if (!save)
			return (NULL);
		free(tmp);
	}
	return (buf);
}

char	*readandsave(int fd, char *save)
{
	char	*buf2;
	char	*tmp;
	int		n;

	buf2 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf2)
		return (NULL);
	while (cutstring1(save) < 0)
	{
		n = (int)read(fd, buf2, BUFFER_SIZE);
		if (n == 0)
		{
			free(buf2);
			return (save);
		}
		if (n < 0)
			return (NULL);
		buf2[n] = '\0';
		tmp = save;
		save = ft_strjoin(save, buf2);
		free(tmp);
	}
	free(buf2);
	return (save);
}

int	cutstring1(char *s)
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

char	*cutstring2(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*c;

	if (!s)
		return (NULL);
	i = cutstring1(s);
	if (i < 0)
		return (NULL);
	len = ft_strlen(s);
	c = malloc(sizeof(char) * (len - i));
	if (!c)
		return (NULL);
	j = 0;
	while (j < len - i)
	{
		c[j] = s[i + j + 1];
		j++;
	}
	return (c);
}

char	*cutstring3(char *s)
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
	return (temp);
}

int main(void)
{
    int   fd;
    char  *s;
	int	i;

	i = 0;
    fd = open("test.txt", O_RDONLY);
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
