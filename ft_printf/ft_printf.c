/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:33:18 by alperrot          #+#    #+#             */
/*   Updated: 2024/02/26 12:40:59 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static size_t	ft_print_s(char *v)
{
	if (!v)
		return (ft_putstr_fd("(null)", 1));
	if (!ft_strlen(v))
		return (0);
	return (ft_putstr_fd(v, 1));
}

static size_t	ft_print_p(void *v)
{
	char	*base;

	if (!*((long unsigned int *) &v))
		return (ft_putstr_fd("(nil)", 1));
	base = "0123456789abcdef";
	write(1, "0x", 2);
	return (ft_putbase_fd(*((long unsigned int *) &v), base, 1) + 2);
}

static size_t	ft_format(const char type, void *v)
{
	size_t	l;

	l = 0;
	if (type == 'c')
		l += write (1, (char *) &v, 1);
	else if (type == 's')
		l += ft_print_s(v);
	else if (type == 'p')
		l += ft_print_p(v);
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

	if (!ft_isvalid(format) || ft_isvalid(format) == -1)
		return (ft_isvalid(format));
	len = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format == '%')
		{
			if (ft_parser(format + 1) == '%')
				len += write(1, "%", 1);
			else
				len += ft_format(ft_parser(format + 1), va_arg(args, void *));
			format += 2;
		}
		if (*format)
		{
			len += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (len);
}
