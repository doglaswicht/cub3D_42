/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:49:38 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/18 18:03:18 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H




/* ---------- OUTRAS UTILS (SEUS) ----------- */

int         clampi(int value, int min, int max);
int         print_error(char *msg);
void        free_map(char **map, int h);

#endif