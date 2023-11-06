/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:48:28 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/06 21:41:38 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i])
		{
			if (str[i] == c && str[i + 1] != '\0')
			{
				i++;
				return (ft_strrchr(&str[i], c));
			}
			i++;
		}
	}
	return ((void *) 0);
}
#include <stdio.h>
int	main()
{
	const char str[] = "test1test1test";
	printf("%s\n", ft_strrchr(str, '1'));
	return (0);
}
