/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:51:47 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/30 21:55:38 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

//FUNCIONES DEL FT_PRINTF PRINCIPAL
int		ft_printf(char const * str, ...);
int		ft_switchTypes(char c,va_list args);
int		ft_printf_char(int c);
int		ft_printf_string(char *s);

//ITOA
char	*ft_itoa(int n);
//PUTCHAR_FD
void	ft_putchar_fd(char c, int fd);

//FT_PRINTF_NUMBER
int		ft_printf_number(int n);
int		ft_printf_unsigned(int n);
int		ft_printf_pointer(int n);

//FUNCIONES DE HEXADECIMAL
int		ft_print_hex(unsigned int num, const char format);

#endif