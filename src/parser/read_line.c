/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:51:31 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/20 00:57:25 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	grow_buffer(char **buf, size_t *cap)
{
	char	*new;

	if (*cap == 0)
		*cap = 64;
	else
		*cap *= 2;
	new = malloc(*cap + 1);
	if (!new)
		return (0);
	if (*buf)
	{
		ft_memcpy(new, *buf, *cap / 2);
		free(*buf);
	}
	*buf = new;
	return (1);
}

static	int	append_char(char **buf, size_t *len, size_t *cap, char c)
{
	if (*len + 1 > *cap)
		if (!grow_buffer(buf, cap))
			return (0);
	(*buf)[(*len)++] = c;
	return (1);
}

char	*read_line(int fd, int *error)
{
	char	c;
	ssize_t	bytes;
	char	*buf;
	size_t	len;
	size_t	cap;

	buf = NULL;
	len = 0;
	cap = 0;
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		if (!append_char(&buf, &len, &cap, c))
			return (*error = 1, NULL);
		if (c == '\n')
			break ;
	}
	if (bytes < 0)
		return (*error = 1, free(buf), NULL);
	if (len == 0)
		return (free(buf), NULL);
	buf[len] = '\0';
	return (buf);
}
