/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:53 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/30 22:10:08 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//TODO: BORRAR ESTA LIBRERIA

#include "ft_printf.h"

int	ft_printf(char const * str, ...)
{
	va_list args; //declaramos el va_list
	//char *s; 
	int	i;
	int	temp;

	va_start(args,str); //inicializamos los argumentos...
	i = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			i++;
			temp += ft_switchTypes(str[i],args);
		}else{
			write(1,&str[i],1);
			temp ++;
		}
		i ++;
	}
	return (temp);
}

int ft_switchTypes(char c,va_list args)
{
	int total_len;

	total_len = 0;
	if(c == 'c') //Char
		total_len += ft_printf_char(va_arg(args,int));
	else if (c == 's') //String
		total_len += ft_printf_string(va_arg(args,char *));
	else if(c == 'd' || c == 'i') // NÚMERO
		total_len += ft_printf_number(va_arg(args,int));
	else if(c == 'u') //UNSIGNED
		total_len += ft_printf_unsigned(va_arg(args,int));
	else if (c == 'p') //PUNTERO
		total_len += ft_printf_pointer(va_arg(args,int));
	else if (c == 'x' || c == 'X')  //HEXADECIMAL
		total_len += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
	{
		write(1,"%",1);
		total_len ++;
	}
	return (total_len);
}

int	ft_printf_char(int c)
{
	write(1,&c,1);
	return (1);
}

int	ft_printf_string(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1,&s[i],1);
		i ++;
	}
	return (i);
}

//COMPILAR Temporal
// gcc -Werror -Wall -Wextra ft_printf.c ft_printf_number.c ft_itoa.c
/*int	main (void)
{
	int resultado = ft_printf("hola%x%i%c\n",55,33,'i');
	printf("Resultado mio: %i\n",resultado);
	resultado = 0;
	resultado = printf("hola%x%i%c\n",55,33,'i');
	printf("Resultado máquina: %i\n",resultado);
	return(0);
}
*/