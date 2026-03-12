/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:16:41 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/02 18:22:04 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function iterates through the format string looking
// for '%' signs. If a '%' is found, it is followed by a
// format specifier that determines how to print the
// value from the argument list. If a regular character outside
// of the argument list is found, it is printed directly to the console.

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		print_size;

	print_size = 0;
	if (!format)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (-1);
			format++;
			print_size += ft_printformat(list, *format);
		}
		else
		{
			print_size += 1;
			ft_putchar_fd(*format, 1);
		}
		format++;
	}
	va_end(list);
	return (print_size);
}
