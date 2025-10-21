/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:34:55 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/14 22:17:09 by dlb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}
/* #include<stdio.h>
int main(void)
{
	const char *text = "tentei mas nao consegui";
	char *resultat = ft_strchr(text,'c');
	printf("%s\n", text);
	if (text != NULL)
	{
		printf("char found: %s\n", resultat);
	}
	else
	{
		printf("char dont foud");
	}
} */
