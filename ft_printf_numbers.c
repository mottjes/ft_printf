/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:42:02 by mottjes           #+#    #+#             */
/*   Updated: 2023/06/13 18:51:53 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(long n, int base, int uppercase)
{
	int		len;
	char	*symbols;
	int		tmp;

	len = 0;
	symbols = "0123456789abcdef";
	if (uppercase)
		symbols = "0123456789ABCDEF";
	if (n < base)
	{
		if (ft_print_char(symbols[n]) == -1)
			return (-1);
		len++;
		return (len);
	}
	else
	{
		tmp = ft_print_digits(n / base, base, uppercase);
		if (tmp == -1)
			return (-1);
		len += tmp;
		return (len += ft_print_digits(n % base, base, uppercase));
	}
}

int	ft_print_numbers(long n, int base, int uppercase)
{
	int		len;
	int		tmp;

	len = 0;
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		n *= -1;
	}
	tmp = ft_print_digits(n, base, uppercase);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	ft_print_address(unsigned long n)
{
	int		len;
	int		tmp;
	char	*symbols;

	symbols = "0123456789abcdef";
	len = 0;
	if (n < 16)
	{
		if (ft_print_char(symbols[n]) == -1)
			return (-1);
		len++;
		return (len);
	}
	else
	{
		tmp = ft_print_address(n / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
		return (len += ft_print_address(n % 16));
	}
}

int	ft_print_ptr(unsigned long n)
{
	int		len;
	int		tmp;

	len = 0;
	if (ft_print_str("0x") == -1)
		return (-1);
	len += 2;
	tmp = ft_print_address(n);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
