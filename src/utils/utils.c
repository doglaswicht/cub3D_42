/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:56:05 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/05 15:12:57 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/** Skips leading spaces in a string. */
char	*skip_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/** Prints an error message and returns -1. */
int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (-1);
}

/** Frees a 2D map array. */
void	free_map(char **map, int h)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/** Prints usage info and returns 1. */
int	print_usage(void)
{
	printf("Usage: ./cub3d <map_file.cub>\n");
	return (1);
}

/** Clamps an integer between min and max. */
int	clampi(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
