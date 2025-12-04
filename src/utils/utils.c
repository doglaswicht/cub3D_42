/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:56:05 by dleite-b          #+#    #+#             */
/*   Updated: 2025/12/04 11:28:59 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
    while (*str == ' ')
        str++;
    return (str);
}

int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (-1);
}

void	free_map(char **map, int h)
{
	if (!map)
		return;
	for (int i = 0; i < h; i++)
			free(map[i]);
	free(map);
}

int	print_usage(void)
{
	printf("Usage: ./cub3d <map_file.cub>\n");
	return (1);
}

// --- util: clamp entier ---
int	clampi(int value, int min, int max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}