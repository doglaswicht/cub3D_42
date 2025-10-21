/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:42:30 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/18 15:03:32 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needdle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needdle == '\0')
	{
		return ((char *)haystack);
	}
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needdle[j] && needdle[j] != '\0')
		{
			j++;
		}
		if (needdle[j] == '\0')
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/* #include<stdio.h>
int main(void)
{
	const char *str = "hoje eu acordei  tao bem, mas tao bem que eu to com fome";
	const char *to_find = "to";

	char *resultat = ft_strnstr(str, to_find, 60);
	
	if (resultat != NULL)
	{
		printf("Substring found : %s\n", resultat);
	}
	else
	{
		printf ("Substring not found\n");
	}
	
} */
