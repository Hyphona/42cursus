/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:50:45 by edmoreau          #+#    #+#             */
/*   Updated: 2023/09/02 17:55:08 by edmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *number)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (number[0] == 0)
		return (0);
	while ((number[i] >= 9 && number[i] <= 13) || number[i] == 32)
		i++;
	while (number[i] == '+' || number[i] == '-')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
	{
		result = number[i] - '0' + result * 10;
		i++;
	}
	return (result);
}
