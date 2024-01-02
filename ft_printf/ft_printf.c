/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:33:18 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/02 09:36:10 by alperrot         ###   ########.fr       */
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
	char	*upper_base;
	char	*lower_base;

	upper_base = "0123456789ABCDEF";
	lower_base = "0123456789abcdef";
	if (type == 'c')
		return (write(1, (char *) &value, 1));
	if (type == 's')
		return (ft_putstr_fd((char *) value, 1));
	if (type == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base_fd(*((unsigned long int *) &value), lower_base, 1) + 2);
	}
	if (type == 'i' || type == 'd')
		return (ft_putnbr_fd(*((int *) &value), 1));
	if (type == 'u')
		return (ft_putnbr_base_fd(*((unsigned long int *) &value), "0123456789", 1));
	if (type == 'x')
		return (ft_putnbr_base_fd(*((unsigned long int *) &value), lower_base, 1));
	if (type == 'X')
		return (ft_putnbr_base_fd(*((unsigned long int *) &value), upper_base, 1));
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
	printf("   printf : %%X : %X\n", 0x45de6fa);
	ft_printf("ft_printf : %%X : %X\n", 0x45de6fa);
}
*/
