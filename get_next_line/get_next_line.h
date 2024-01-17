/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:52 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/17 09:16:11 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>

void    ft_bzero(char *str);
char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);

#endif