/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:33:18 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 10:27:53 by alperrot         ###   ########.fr       */
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

static int	ft_printf_formatter(const char type, void *v)
{
	size_t	l;

	l = 0;
	if (type == 'c')
		l += write(1, (char *) &v, 1);
	else if (type == 's')
		l += ft_putstr_fd((char *) v, 1);
	else if (type == 'p')
	{
		l += write(1, "0x", 2);
		l += ft_putbase_fd(*((long unsigned int *) &v), "0123456789abcdef" ,1);
	}
	else if (type == 'i' || type == 'd')
		l += ft_putnbr_fd(*((int *) &v), 1);
	else if (type == 'u')
		l += ft_putbase_fd(*((unsigned int *) &v), "0123456789", 1);
	else if (type == 'x')
		l += ft_putbase_fd(*((unsigned int *) &v), "0123456789abcdef", 1);
	else if (type == 'X')
		l += ft_putbase_fd(*((unsigned int *) &v), "0123456789ABCDEF", 1);
	return (l);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;
	char	type;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format == '%')
		{
			type = ft_printf_parser(format + 1);
			if (type)
			{
				if (type == '%')
					len += write(1, "%", 1);
				else
					len += ft_printf_formatter(type, va_arg(args, void *));
			}
			format += 2;
		}
		len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	char			*p;
	unsigned int	i;
	
	i = 4294967295;
	printf("   printf : %%c : %c\n", 'a');
	ft_printf("ft_printf : %%c : %c\n", 'a');
	printf("   printf : %%s : %s\n", "0123456789abcdef");
	ft_printf("ft_printf : %%s : %s\n", "0123456789abcdef");
	printf("   printf : %%p : %p\n", &p);
	ft_printf("ft_printf : %%p : %p\n", &p);
	printf("   printf : %%i : %i\n", -42);
	ft_printf("ft_printf : %%i : %i\n", -42);
	printf("   printf : %%d : %d\n", 42);
	ft_printf("ft_printf : %%d : %d\n", 42);
	printf("   printf : %%u : %u\n", i);
	ft_printf("ft_printf : %%u : %u\n", i);
	printf("   printf : %%x : %x\n", 0x45de6fa);
	ft_printf("ft_printf : %%x : %x\n", 0x45de6fa);
	printf("   printf : %%X : %X\n", 0xFFFFFFFF);
	ft_printf("ft_printf : %%X : %X\n", 0xFFFFFFFF);
}
*/