/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:20:33 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/11 17:44:34 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buffer;

	buffer = (unsigned char *)b;
	while (len > 0)
	{
		*buffer = (unsigned char)c;
		buffer++;
		len--;
	}
	return (b);
}
/* #include<stdio.h>
int main()
{
	char dest[10];
	ft_memset(dest, 'B', 5);
	printf("Resultat du memset:\n");
	
	int i = 0;
	while (i < 10)
	{
		printf("%c", dest[i]);
		i++;
	}
}*/
