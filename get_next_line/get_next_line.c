/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/29 15:23:06 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_hasline(char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
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
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (i);
}

static void ft_uptmp(char  *tmp)
{
    size_t  i;
    size_t  j;

    i = ft_linelen(tmp) + 1;
    j = 0;
    while (tmp[i])
    {
        tmp[j] = tmp[i];
        j++;
        i++;
    }
    tmp[j] = '\0';
}

static char *ft_sendline(char **str)
{
    size_t  i;
    char    *dst;
    
    i = 0;
    if (str[0][0] == 0)
    {
        dst = malloc(sizeof(char) * 1);
        if (!dst)
            return (0);
        dst[0] = 0;
        free(*str);
        *str = NULL;
        return (dst);
    }
    else
        dst = malloc((sizeof(char) * ft_linelen(*str)) + 2);
    if (!dst)
        return (0);
    while (i <= ft_linelen(*str))
    {
        dst[i] = str[0][i];
        i++;
    }
    dst[i] = 0;
    if (str[0][i])
        ft_uptmp(*str);
    else
    {
        free(*str);
        *str = NULL;
    }
    return (dst);
}

char    *get_next_line(int fd)
{
    char            *buf;
    static char     *tmp;
    int             state;

    if (!fd || !BUFFER_SIZE)
        return (0);
    if (tmp && ft_hasline(tmp))
        return (ft_sendline(&tmp));
    if (!tmp)
        tmp = ft_strjoin(NULL, NULL);
    buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (!buf)
        return (0);
    buf[BUFFER_SIZE] = '\0';
    state = -1;
    tmp = ft_strjoin(tmp, NULL);
    while (state)
    {
        state = read(fd, buf, BUFFER_SIZE);
        if (state == -1)
            return (0);
        buf[state] = 0;
        tmp = ft_strjoin(tmp, buf);
        if (ft_hasline(buf))
            break ;
    }
    free(buf);
    buf = NULL;
    return (ft_sendline(&tmp));
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
    while (i < 6)
    {
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
        i++;
    }
    close(fd);
}
