/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/24 09:23:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_hasline(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (0);
}

static size_t   ft_linelen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (i);
}

static char *ft_uptmp(char  *tmp)
{
    size_t  i;
    size_t  size;
    char    *n_tmp;

    i = ft_linelen(tmp);
    size = 0;
    while (tmp[size])
        size++;
    size = size - i;
    n_tmp = malloc((sizeof(char) * size) + 1);
    if (!n_tmp)
        return (0);
    size = 0;
    while (tmp[i])
    {
        n_tmp[size] = tmp[i];
        size++;
        i++;
    }
    n_tmp[size] = '\0';
    free(tmp);
    return (n_tmp);
}

static char *ft_sendline(char *str)
{
    size_t  i;
    char    *dst;
    
    i = 0;
    dst = malloc((sizeof(char) * ft_linelen(str)) + 1);
    if (!dst)
        return (0);
    dst[ft_linelen(str) + 1] = '\0';
    while (i <= ft_linelen(str))
    {
        dst[i] = str[i];
        i++;
    }
    if (str[i + 1])
        ft_uptmp(str);
    else
        free(str);
    return (dst);
}

char    *get_next_line(int fd)
{
    char            *buf;
    static char     *tmp;
    int             state;

    if (!fd || !BUFFER_SIZE)
        return(0);
    if (tmp)
    {
        if (ft_hasline(tmp))
            return (ft_sendline(tmp));
    }
    else
        tmp = "";
    buf = malloc((sizeof(char) + BUFFER_SIZE) + 1);
    if (!buf)
        return (0);
    buf[BUFFER_SIZE + 1] = '\0';
    state = -1;
    while (state)
    {
        state = read(fd, buf, BUFFER_SIZE);
        if (ft_hasline(buf))
            break ;
    }
    tmp = ft_strjoin(buf, tmp);
    free(buf);
    return (ft_sendline(tmp));
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
