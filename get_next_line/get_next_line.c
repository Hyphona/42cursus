/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/17 12:04:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  ft_hasline(char *buf)
{
    size_t  len;

    len = 0;
    while (buf[len])
    {
        if (buf[len] == '\n')
            return (len);
        len++;
    }
    return (0);
}

static size_t   ft_linelen(char *str)
{
    size_t  len;

    len = 0;
    while (str[len])
    {
        if (str[len] == '\n')
            return (len + 1);
        len++;
    }
    return (len);
}

static char    *ft_linecpy(char *tmp)
{
    int         i;
    char        *dst;

    i = 0;
    dst = malloc((sizeof(char) * ft_linelen(tmp)) + 1);
    if (!dst)
        return((void *) 0);
    while (tmp[i])
    {
        if (tmp[i] == '\n')
        {
            dst[i] = tmp[i];
            dst[i + 1] = '\0';
            break ;
        }
        dst[i] = tmp[i];
        i++;
    }
    free(tmp);
    return (dst);
}

static void ft_savelast(char *buf, char *dst)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (buf[i] != '\n')
        i++;
    i++;
    while (buf[i])
    {
        dst[j] = buf[i];
        i++;
        j++;
    }
    dst[j] = '\0';
}

char    *get_next_line(int fd)
{
    static char     *last;
    char            *buf;
    char            *tmp;
    int             state;

    if (!fd || !BUFFER_SIZE)
        return((void *) 0);
    buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (!buf)
        return ((void *) 0);
    state = -1;
    tmp = "";
    while (state)
    {
        state = read(fd, buf, BUFFER_SIZE);
        buf[state] = '\0';
        if (last)
            tmp = ft_strjoin(tmp, last);
        tmp = ft_strjoin(tmp, buf);
        if (ft_hasline(buf))
            break ;
    }
    last = malloc((sizeof(char) * (BUFFER_SIZE - ft_hasline(buf))) + 1);
    if (!last)
        return ((void *) 0);
    ft_savelast(buf, last);
    free(buf);
    return (ft_linecpy(tmp));
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    char    *str;
    int     fd;
    int i;

    i = 0;
    fd = open("text.txt", O_RDONLY);
    while (i < 5)
    {
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
        i++;
    }
    close(fd);
}
