/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:47:58 by alperrot          #+#    #+#             */
/*   Updated: 2023/09/07 14:29:17 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[counter])
		{
			while (to_find[counter])
			{
				if (str[i + counter] == to_find[counter])
					if (counter == ft_strlen(to_find))
						return (&str[i]);
				counter++;
			}
			counter = 0;
		}
		i++;
	}
	return ((char *) 0);
}
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%s\n", ft_strstr("", ""));
	printf("%s\n", strstr("", ""));
}
