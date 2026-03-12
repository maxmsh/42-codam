/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:11:11 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/02 17:58:58 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_printdigit(int n);
int	ft_printstring(char *string);
int	ft_printhex(unsigned int numb, const char *symbols);
int	ft_pointer_address(size_t list);
int	ft_printunsigned(unsigned int num);
int	ft_printformat(va_list list, char const format);
int	ft_pointer_to_hex(unsigned long num, char format);
int	ft_printlong(size_t numb, const char *symbols);
#endif