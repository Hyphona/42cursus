/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:40:19 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 12:17:16 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_atoi_base(const char *str, char *base);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_check_base(char *base);
size_t	ft_countword(char const *s, char c);
int		ft_factorial(int nb);
int		ft_find_next_prime(int nb);
size_t	ft_intlen(int n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isprime(int nb);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isxdigit(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_power(int nb, int power);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putendl_fd(char *s, int fd);
size_t	ft_putbase_fd(long unsigned int n, char *base, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_sqrt(int nb);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const*s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strnstr(const char *str1, const char *str2, size_t size);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
