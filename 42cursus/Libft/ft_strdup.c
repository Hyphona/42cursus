/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:43:53 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 15:50:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return ((void *) 0);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}
