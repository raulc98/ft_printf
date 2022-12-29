/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:53 by rcabrero          #+#    #+#             */
/*   Updated: 2022/12/29 15:31:00 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		temp;

	va_start(args, str);
	i = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			temp += ft_switchTypes(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			temp ++;
		}
		i ++;
	}
	return (temp);
}

int	ft_switchTypes(char c, va_list args)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_printf_char(va_arg(args, int));
	else if (c == 's')
		total += ft_printf_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		total += ft_printf_number(va_arg(args, int));
	else if (c == 'u')
		total += ft_printf_unsigned(va_arg(args, int));
	else if (c == 'p')
		total += ft_printf_pointer(va_arg(args, unsigned long long));
	else if (c == 'x' || c == 'X')
		total += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
	{
		write(1, "%", 1);
		total ++;
	}
	return (total);
}

int	ft_printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_string(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_print_null());
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i ++;
	}
	return (i);
}

int	ft_print_null(void)
{
	char	*nullPaint;
	int		i;

	i = 0;
	nullPaint = "(null)";
	while (nullPaint[i] != '\0')
	{
		write(1, &nullPaint[i], 1);
		i ++;
	}
	return (6);
}

//COMPILAR Temporal
//gcc -Werror -Wall -Wextra ft_printf.c ft_printf_number.c 
///ft_itoa.c ft_putchar_fd.c ft_printf_hexadecimal.c ft_printf_pointer.c 
/*
#include <stdio.h>
int	main (void)
{

	//printf(" %u ", -10);
	//printf("\n");
	ft_printf(" %u ", 936);
	printf("\n");
	//ft_printf("Mi printf: %u\n", -2);
	//printf("Printf de la maquina: %u\n", -2);
	return(0);
}
*/
//	TEST(2, print(" %u ", -1));
