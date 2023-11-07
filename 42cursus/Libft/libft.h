/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:40:19 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 11:47:54 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi(const char *str);
void	ft_bzero(void *src, int n);
int	ft_isalnum(int arg);
int	ft_alpha(int arg);
int	ft_isascii(int arg);
int	ft_isdigit(int arg);
int	ft_isprint(int arg);
void	*ft_memchr(const void *str, int c, size_t size);
int	ft_memcmp(const void *str1, const void *str2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *str1, const void *str2, size_t size);
void	*ft_memset(void *str, int c, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strnstr(const char *str1, const char *str2, size_t max);
char	*ft_strrchr(const char *str, int c);
int	ft_tolower(int arg);
int	ft_toupper(int arg);
