/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:02:42 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/11 19:38:36 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (len > 0)
	{
		*ptr = 0;
		ptr++;
		len--;
	}
}
/* #include<stdio.h>
int	main()
{
	char s[10];
	ft_bzero(s, 10);
	printf("Resultat de ft_bzero\n");
	int i = 0;
	while (i < 10)
	{
		printf("%c", s[i]);
		i++;
	}
} */
