/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:38:36 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/28 16:56:36 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list ap, int *ptr_len)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		len = ft_print_numbers((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		len = ft_print_digits(va_arg(ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		len = ft_print_digits(va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		len = ft_print_digits(va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		len = ft_print_ptr(va_arg(ap, unsigned long));
	else if (specifier == '%')
		len = ft_print_char('%');
	if (len == -1)
		return (-1);
	return (*ptr_len += len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (print_format(*(++format), ap, &len) == -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(*format) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
