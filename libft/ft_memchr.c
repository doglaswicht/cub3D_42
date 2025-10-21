/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:40:41 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/11 17:42:52 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;

	while (n != 0)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}
/* #include<stdio.h>
int main(void)
{
	char *str = "found the $ spion";
	char *resultat = ft_memchr(str, '$', 11);

	if (resultat != NULL)
	{
		printf("espion est: %s\n", resultat);
	}
	else
	{
		printf("espion dont found\n");
	}

} */
