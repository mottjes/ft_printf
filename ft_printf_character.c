/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:43:41 by mottjes           #+#    #+#             */
/*   Updated: 2023/06/13 18:44:30 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (len += ft_print_str("(null)"));
	while (*str)
	{
		if (ft_print_char(*str) == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}
