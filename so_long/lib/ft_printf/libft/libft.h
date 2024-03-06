/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:40:19 by alperrot          #+#    #+#             */
/*   Updated: 2024/02/29 10:55:41 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_check_base(char *base);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putendl_fd(char *s, int fd);
size_t	ft_putbase_fd(long unsigned int n, char *base, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
