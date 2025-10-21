/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doglasbastos <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:54:32 by doglasbas         #+#    #+#             */
/*   Updated: 2024/10/14 15:02:29 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	fft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = fft_strlen(dest);
	len_src = fft_strlen(src);
	if (n <= len_dest)
	{
		return (len_src + n);
	}
	i = 0;
	while (src[i] != '\0' && (len_dest + i) < (n - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

/* #include<stdio.h>
int main(void)
{
	char buffer1[25] = "jai ";
	ft_strlcat(buffer1, "reussi!", sizeof(buffer1));
	printf("%s", buffer1);

} */
