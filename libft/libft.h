/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:58:11 by dleite-b          #+#    #+#             */
/*   Updated: 2024/10/18 15:19:01 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int character);
int		ft_strlen(char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needdle, size_t len);

#endif
