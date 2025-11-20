/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:40:31 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/20 01:19:12 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Retorna 1 se (x, y) é um muro OU está fora do mapa
*/
int	is_wall(const t_world *w, double x, double y)
{
	int	mx;
	int	my;
	int	line_len;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || my < 0 || my >= w->map_h)
		return (1);
	if (!w->map[my])
		return (1);
	line_len = ft_strlen(w->map[my]);
	if (mx >= line_len)
		return (1);
	if (w->map[my][mx] == '1')
		return (1);
	return (0);
}
