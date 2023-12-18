/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:33:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/18 12:34:56 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static char	ft_printf_parser(const char *str)
{
	char	*types;

	types = "cspdiuxX%";
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
		return (ft_putstr_fd((char *) value, 1));
	if (type == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base_fd(*((int *) &value), "0123456789abcdef", 1) + 2);
	}
	if (type == 'i' || type == 'd')
		return (ft_putnbr_base_fd(*((int *) &value), "0123456789", 1));
	if (type == 'x')
		return (ft_putnbr_base_fd(*((int *) &value), "0123456789abcdef", 1));
	if (type == 'X')
		return (ft_putnbr_base_fd(*((int *) &value), "0123456789ABCDEF", 1));
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
			type = ft_printf_parser(format + 1);
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
//	char	*p;
//
//	p = "Hello World!";
//	ft_printf("%s | %c | %% | %%%s%c | %i | %d | %x | %X | %p\n", "Hello World!", 'A', "BCD", 'E', 123456, 654321, ft_atoi_base("36fe2a", "0123456789abcdef"), 0x36fe2a, p);
//	return (0);
//}
