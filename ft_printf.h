/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:01:01 by mottjes           #+#    #+#             */
/*   Updated: 2023/06/13 18:51:29 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digits(long n, int base, int uppercase);
int		ft_print_numbers(long n, int base, int uppercase);
int		t_print_address(unsigned long n);
int		ft_print_ptr(unsigned long n);

#endif