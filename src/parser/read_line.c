/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:51:31 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/04 11:52:21 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

char	*read_line(int fd, int *error)
{
	char	*line;

	if (error)
		*error = 0;
	errno = 0;
	line = get_next_line(fd);
	if (!line && error && errno)
		*error = 1;
	return (line);
}
