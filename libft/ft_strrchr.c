/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doglasbastos <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:00:23 by doglasbas         #+#    #+#             */
/*   Updated: 2024/10/11 17:47:12 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	else
	{
		return ((char *)last);
	}
}
/* #include<stdio.h>
int main(void)
{
	const char *str = "Paralelepipedo";
	char *resultat = ft_strrchr(str, 'e');

	if (resultat != NULL)
	{
		printf(" le dernier char trouvé: %s\n", resultat);
	}
	else
	{
		printf("char not found\n");
	}
} */
