/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:49:01 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/18 14:59:48 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*dst;
	const unsigned char	*source;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		while (count-- > 0)
			dst[count] = source[count];
	}
	else
	{
		while (i < count)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dst);
}
/* #include<stdio.h>
int main(void)
{
	char src[] = "Bresil";
	char dest[] = "paro";

	{
		ft_memmove(dest + 2 , src, 4);
		printf("%s", dest);
	}
} */
