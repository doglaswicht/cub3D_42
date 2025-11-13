/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:11:09 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/10 14:13:56 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  parse_component(const char **str, int *component)
{
    long    value;

    while (**str == ' ')
        (*str)++;
    if (**str < '0' || **str > '9')
        return (print_error("Invalid RGB value"));
    value = 0;
    while (**str >= '0' && **str <= '9')
    {
        value = value * 10 + (**str - '0');
        if (value > 255)
            return (print_error("RGB component out of range"));
        (*str)++;
    }
    while (**str == ' ')
        (*str)++;
    *component = (int)value;
    return (0);
}

int parse_rgb(const char *str, int *out_color)
{
    int r;
    int g;
    int b;

    if (!str || !out_color)
        return (print_error("Invalid RGB pointer"));
    if (parse_component(&str, &r) == -1)
        return (-1);
    if (*str != ',')
        return (print_error("RGB values must be separated by commas"));
    str++;
    if (parse_component(&str, &g) == -1)
        return (-1);
    if (*str != ',')
        return (print_error("RGB values must be separated by commas"));
    str++;
    if (parse_component(&str, &b) == -1)
        return (-1);
    if (*str != '\0')
    {
        while (*str == ' ')
            str++;
        if (*str != '\0')
            return (print_error("Unexpected characters after RGB value"));
    }
    *out_color = (r << 16) | (g << 8) | b;
    return (0);
}