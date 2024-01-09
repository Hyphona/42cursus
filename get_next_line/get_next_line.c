/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/09 14:06:57 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_linelen(char *file)
{
    size_t  len;

    len = 0;
    while (*file)
    {
        if (*file == '\n')
            return (len + 1);
        file++;
        len++;
    }
    return (len);
}

static char    *ft_linecpy(char *buffer, char *dst)
{
    static int  last;
    int         i;

    i = last;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            break ;
        dst[i - last] = buffer[i];
        i++;
    }
    dst[i - last] = buffer[i];
    last = i + 1;
    free(buffer);
    return (dst);
}

char    *get_next_line(int fd)
{
    size_t      l_len;
    char        *buffer;
    char        *dst;
    int         file;

    if (!fd || !BUFFER_SIZE)
        return ((void *) 0);
    buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (!buffer)
        return ((void *) 0);
    file = read(fd, buffer, BUFFER_SIZE);
    if (!file)
        return ((void *) 0);
    l_len = ft_linelen(buffer);
    dst = malloc((sizeof(char) * l_len) + 1);
    if (!dst)
        return ((void *) 0);
    return (ft_linecpy(buffer, dst));
}
/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
    printf("%s", get_next_line(open("text.txt", O_RDONLY)));
    printf("%s", get_next_line(open("text.txt", O_RDONLY)));
    printf("%s", get_next_line(open("text.txt", O_RDONLY)));
    printf("%s", get_next_line(open("text.txt", O_RDONLY)));
    printf("%s", get_next_line(open("text.txt", O_RDONLY)));
}
*/