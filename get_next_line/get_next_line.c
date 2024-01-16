/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/16 10:25:16 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_strlen(char const *str)
{
    size_t  i;

    i = 0;
    while(*str)
    {
        str++;
        i++;
    }
    return(i);
}

char	*ft_strjoin(char const *s1, char const*s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((void *) 0);
	str = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))) + 1);
	if (!str)
		return ((void *) 0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	return (str);
}

static int  ft_hasline(char *line)
{
    while (*line)
    {
        if (*line == '\n')
            return (1);
        line++;
    }
    return (0);
}

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

char    *get_next_line(int fd)
{
    static size_t   offset;
    char            *buf;
    char            *tmp;
    int             state;

    if (!fd || !BUFFER_SIZE)
        return ((void *) 0);
    buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (!buf)
        return((void *) 0);
    state = -1;
    tmp = "";
    if (offset > 0)
            state = read(fd, buf, offset);
    while (state != 0)
    {
        state = read(fd, buf, BUFFER_SIZE);
        tmp = ft_strjoin(tmp, buf);
        offset = offset + ft_linelen(tmp);
        if (ft_hasline(buf))
            break ;
    }
    free(buf);
    return (ft_linecpy(tmp));
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