/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:10:13 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/18 14:33:35 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*c;
	size_t	len1;
	size_t	len2;

	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	c = malloc(sizeof(char) * (len1 + len2 + 1));
	if (c == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(c, s1, len1);
	ft_memcpy(c + len1, s2, len2);
	c[len1 + len2] = '\0';
	free(s1);
	return (c);
}

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	if (!src)
		return (NULL);
	p = malloc(ft_strlen(src) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*change_null(char *s)
{
	free(s);
	return (NULL);
}
