/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:43:53 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 12:08:16 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!cpy)
		return ((void *) 0);
	ft_strlcpy(cpy, s, ft_strlen(s) + 1);
	return (cpy);
}
