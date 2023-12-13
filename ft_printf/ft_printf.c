/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:33:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/13 17:04:01 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
//#include <unistd.h>
//#include <stddef.h>

static int	ft_printf_parser(const char c, void *value)
{
	if (c == 'c')
	{
		write(1, (char *) &value, 1);
		return (1);
	}
	if (c == 's')
	{
		write(1, (char *) value, ft_strlen((char *) value));
		return (ft_strlen((char *) value));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	lenght;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				lenght++;
			}
			else
				lenght += ft_printf_parser(*format, va_arg(args, void *));
		}
		write(1, format, 1);
		lenght++;
		format++;
	}
	va_end(args);
	return (lenght);
}

//int	main(void)
//{
//	ft_printf("Hello %s! | %c%c | %% |\n", "World", 'A', 'B');
//	return (0);
//}
