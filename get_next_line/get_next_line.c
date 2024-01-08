/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/08 12:17:21 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_linelen(char *file)
{
    size_t  len;

    len = 0;
    while (*file != '\n')
    {
        file++;
        len++;
    }
    return (len + 1);
}

char    *get_next_line(int fd)
{
    static int  last;
    size_t      len;
    int         file;
    char        *line;
    char        *buffer;
    
    if (!fd || BUFFER_SIZE <= 1)
        return ((void *) 0);
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return ((void *) 0);
    file = read(fd, buffer, BUFFER_SIZE);
    if (!file)
        return ((void *) 0);
    len = ft_linelen(&buffer[last]);
    line = malloc(sizeof(char) * len + 1);
    if (!line)
        return ((void *) 0);
    line[len] = '\n';
    len--;
    while (len != 0)
    {
        line[len] = buffer[len + last];
        len--;
    }
    last += ft_linelen(&buffer[last]);
    free(buffer);
    return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
    printf("%s", get_next_line(open("./text.txt", O_RDONLY)));
}
