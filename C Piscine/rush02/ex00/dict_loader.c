/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:21:50 by alperrot          #+#    #+#             */
/*   Updated: 2023/09/03 12:39:07 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_fix_dict(char *dict);

static char	*ft_load_dict(char *dict_name)
{
	int		file;
	char	*content;

	content = malloc(1024 + 1);
	content[0] = '\0';
	if (content == NULL)
		return (content);
	file = open(dict_name, O_RDONLY);
	if (file < 0)
		return (content);
	read(file, content, 1024);
	close(file);
	return (content);
}

char	*ft_init_dict(char *dict_name)
{
	char	*dict;

	dict = ft_load_dict(dict_name);
	if (dict[0] == '\0')
		return (dict);
	return (ft_fix_dict((dict)));
}
