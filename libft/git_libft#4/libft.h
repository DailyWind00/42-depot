/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:09:47 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/18 15:58:38 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stddef.h>
//size_t -> void -> char -> int
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_bzero(void *dst, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t length);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *vptr, int value, size_t count);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(char *str);
int		ft_isalnum(int C);
int		ft_isalpha(int C);
int		ft_isascii(int C);
int		ft_isdigit(int C);
int		ft_isprint(int C);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int C);
int		toupper(int C);

#endif
