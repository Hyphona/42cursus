/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/09 13:15:58 by alperrot         ###   ########.fr       */
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

char    *get_next_line(int fd)
{
    static int  last;
    size_t      l_len;
    char        *buffer;
    char        *line;
    int         file;
    int         i;

    if (!fd || !BUFFER_SIZE)
        return ((void *) 0);
    buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (!buffer)
        return ((void *) 0);
    file = read(fd, buffer, BUFFER_SIZE);
    if (!file)
        return ((void *) 0);
    l_len = ft_linelen(buffer);
    line = malloc((sizeof(char) * l_len) + 1);
    if (!line)
        return ((void *) 0);
    i = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
        {
            line[i] = '\n';
            last++;
            free(buffer);
            return (line);
        }
        line[i] = buffer[i];
        i++;
        last++;
    }
    free(buffer);
    return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
    printf("%s", get_next_line(open("text.txt", O_RDONLY)));
}
*/