/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:59:02 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/19 12:25:38 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_base(char *base)
{
	if (!base || ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	while (*base)
	{
		if (!ft_isalnum(*base))
			return (0);
		base++;
	}
	return (1);
}
