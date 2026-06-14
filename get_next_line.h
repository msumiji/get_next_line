/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:10:44 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/14 19:40:32 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

int		cutstring1(char *s);

char	*cutstring2(char *s);

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(char *s1, char const *s2);

char	*ft_strdup(const char *src);

char	*readandsave(int fd, char *save);

char	*cutstring3(char *s);

#endif
