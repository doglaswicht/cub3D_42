/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:32 by dleite-b          #+#    #+#             */
/*   Updated: 2025/11/16 21:51:14 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

int print_error(char *msg)
{
    printf("Error\n%s\n", msg);
    return (-1);
}

void	die(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	error(const char *ctx, const char *detail)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)ctx, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd((char *)detail, 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}
