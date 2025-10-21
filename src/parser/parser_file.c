/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:41:54 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/21 17:10:13 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int parse_cub(char *path, t_game *game)
{
    int fd;
    (void)game;/*resolver*/

    fd = open(path, O_RDONLY);
    if(fd < 0)
    {
        printf("Error\nCannot open file: %s\n", path);
        return (-1);
    }

    //lire et valider la map

    close(fd);
    return (0);
}