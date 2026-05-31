/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/05/31 19:12:40 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd)
{
	static char *save;
	char	*buf;
	char	*new;

	buf = malloc(BUFFER_SIZE + 1);
	if (read(fd, buf, BUFFER_SIZE) < 0)
		return (NULL);
	new = ft_strjoin(save, buf);
	save = new;
}
