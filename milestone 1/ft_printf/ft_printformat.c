/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:31:14 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/01 18:52:02 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function assigns a corresponding function
// to a format specifier (the character after the '%' sign).
// It will always return the amount of bytes written.

int	ft_printformat(va_list list, char const specifier)
{
	int	print_size;

	print_size = 0;
	if (specifier == 'c')
	{
		ft_putchar_fd(va_arg(list, int), 1);
		print_size++;
	}
	else if (specifier == 's')
		print_size += ft_printstring(va_arg(list, char *));
	else if (specifier == 'p')
		print_size += ft_pointer_address(va_arg(list, size_t));
	else if (specifier == 'd' || specifier == 'i')
		print_size += ft_printdigit(va_arg(list, int));
	else if (specifier == 'u')
		print_size += ft_printunsigned((va_arg(list, unsigned int)));
	else if (specifier == 'x')
		print_size += ft_printhex(va_arg(list, unsigned int), HEX_LOWER);
	else if (specifier == 'X')
		print_size += ft_printhex(va_arg(list, unsigned int), HEX_UPPER);
	else if (specifier == '%' && ++print_size)
		ft_putchar_fd(specifier, 1);
	else
		return (-1);
	return (print_size);
}
