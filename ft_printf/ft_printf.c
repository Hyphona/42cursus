/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:33:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/14 11:54:55 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

static char	ft_printf_parser(const char *str)
{
	char	*types;

	types = "cspdiuxX%";
	str++;
	while (*types)
	{
		if (*str == *types)
			return (*types);
		types++;
	}
	return (0);
}

static int	ft_printf_formatter(const char type, void *value)
{
	if (type == 'c')
		return (write(1, (char *) &value, 1));
	if (type == 's')
		return (write(1, (char *) value, ft_strlen((char *) value)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	lenght;
	char	type;

	lenght = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format == '%')
		{
			type = ft_printf_parser(format);
			if (type)
			{
				if (type == '%')
					lenght += write(1, &"%", 1);
				else
					lenght += ft_printf_formatter(type, va_arg(args, void *));
			}
			format += 2;
		}
		lenght += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (lenght);
}

//int	main(void)
//{
//	ft_printf("%s | %c%c | %% | %%%s%c | \n", "Hello World!", 'A', 'B', "CDE", 'F');
//	return (0);
//}