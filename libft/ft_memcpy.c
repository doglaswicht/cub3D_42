/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:56:57 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/18 14:36:32 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char	*dest;
	const unsigned char	*src;
	size_t	i;

	if (!destination && !source)
	{
		return (NULL);
	}
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
/* #include<stdio.h>
int main()
{
	char src[10] = "doglas";
	char dest[10];

	ft_memcpy(dest, src, 9);
	printf("Valeur src = Doglas\n");
	printf("valeur dest = %s", dest);
} */
