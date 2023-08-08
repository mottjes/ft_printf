/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:44:06 by mottjes           #+#    #+#             */
/*   Updated: 2023/06/08 13:54:26 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count += print_string("(null)"));
	while (*str)
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}

int	print_pointer(unsigned long n, int print_start)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (print_start)
	{
		count += print_string("0x");
		print_start = 0;
	}
	if (n < 16)
		return (count += print_char(symbols[n]));
	else
	{
		count += print_pointer(n / 16, print_start);
		return (count += print_pointer(n % 16, print_start));
	}
}

int	print_digits(long n, int base, int uppercase)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (uppercase)
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		print_char('-');
		return (print_digits(-n, base, uppercase) + 1);
	}
	else if (n < base)
		return (count += print_char(symbols[n]));
	else
	{
		count += print_digits(n / base, base, uppercase);
		return (count += print_digits(n % base, base, uppercase));
	}
}
