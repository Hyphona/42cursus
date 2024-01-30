/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:03:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/30 10:11:37 by alperrot         ###   ########.fr       */
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
	
	if (!*str[0])
	{
		ft_free(str);
		return ((char *) '\0');
	}
	else
		dst = malloc((sizeof(char) * ft_linelen(*str)) + 2);
	if (!dst)
		return ((char *) '\0');
	i = 0;
	while (i <= ft_linelen(*str))
	{
		dst[i] = str[0][i];
		i++;
	}
	dst[i] = '\0';
	if (str[0][i - 1])
		ft_uptmp(*str);
	else
		ft_free(str);
	return (dst);
}

char    *get_next_line(int fd)
{
	char            *buf;
	static char     *tmp;
	int             state;

	if (fd < 0 || BUFFER_SIZE < 1)
		return ((char *) '\0');
	if (tmp && ft_hasline(tmp))
		return (ft_sendline(&tmp));
	buf = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return ((char *) '\0');
	state = -1;
	while (state)
	{
		state = read(fd, buf, BUFFER_SIZE);
		if (state == -1)
		{
			free(buf);
			return ((char *) '\0');
		}
		buf[state] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (ft_hasline(buf))
			break ;
	}
	free(buf);
	return (ft_sendline(&tmp));
}

/*#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char    *str;
	int     fd;
	int i;

	i = 0;
	fd = open("text.txt", O_RDWR);
	fd = 1000;
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
}*/