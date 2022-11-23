/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:53 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/23 20:29:25 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//TODO: BORRAR ESTA LIBRERIA


#include "Library/ft_printf.h"
#include "Library/libft.h"


int	ft_printf(char const * str, ...)
{
	va_list args; //declaramos el va_list
	//char *s;
	int	i;
	va_start(args,str); //inicializamos los argumentos...
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			i ++;
			ft_switchTypes(str[i],args);
		}else{
			write(1,&str[i],1);	
		}
		i ++;
	}
	printf("\n");
	//int sx = va_arg(args, int);
	
	//printf("Prueba %i\n",char*(sx));
	//unionPrueba = va_arg(args,my_union_t);
	
	//printf("Segundoooo: %s\n",s);
	return (0);
}

//necesito pasar la posicion y la siguiente posicion del string
void ft_switchTypes(char c,va_list args)
{
	if(c == 'c') //Char
		ft_printf_char(va_arg(args,int));
	if (c == 's') //String
		ft_printf_string(va_arg(args,char *));
	/*
	if(c == 'd')
		ft_printf_float(va_arg(args,double));
	*/
}

void	ft_printf_char(int c)
{
	write(1,&c,1);
}

void	ft_printf_string(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1,&s[i],1);
		i ++;
	}	
}

int	main (void)
{
	printf("HOLA QUE%c TAL%d\n",'S',334);
	//printf("HOLA QUE%c TAL%s",'`',"HOLA");
	//printf("hola%cHola", "OsaS");
	//printf("\n");
	return(0);
}