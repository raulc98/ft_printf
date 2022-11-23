/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:51:47 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/23 20:12:28 by rcabrero         ###   ########.fr       */
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
void	ft_switchTypes(char c,va_list args);
void	ft_printf_char(int c);
void	ft_printf_string(char *s);

//FUNCIONES DE FT_PRINTF_DECIMAL

void	ft_printf_float(double d);
size_t	doubleLen(double d);

#endif