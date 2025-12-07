/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturny <csturny@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:35:03 by csturny           #+#    #+#             */
/*   Updated: 2025/12/07 15:35:23 by csturny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Returns the current time in seconds.
 *
 * Uses gettimeofday to obtain the current time with microsecond precision,
 * and converts it to a double representing seconds.
 *
 * @return The current time in seconds (with microsecond precision).
 */
double	get_time_in_seconds(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((double)now.tv_sec + (double)now.tv_usec / 1000000.0);
}

void	print_fps(void)
{
	static struct timeval	last = {0, 0};
	static int				frames = 0;
	struct timeval			now;
	double					elapsed;

	gettimeofday(&now, NULL);
	frames++;
	if (last.tv_sec == 0)
		last = now;
	elapsed = (now.tv_sec - last.tv_sec)
		+ (now.tv_usec - last.tv_usec) / 1000000.0;
	if (elapsed >= 1.0)
	{
		printf("FPS: %d\n", frames);
		frames = 0;
		last = now;
	}
}
