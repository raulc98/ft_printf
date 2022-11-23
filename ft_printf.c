/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:53 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/23 16:21:43 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_switchTypes(char c,va_list args);
void	ft_printf_char(int c);
void	ft_printf_string(char *s);

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
	if(c == 'c') //c
		ft_printf_char(va_arg(args,int));
	if (c == 's')
		ft_printf_string(va_arg(args,char *));

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
	ft_printf("HOLA QUE%c TAL%s\n",'S',"  HOLA");
	//printf("HOLA QUE%c TAL%s",'`',"HOLA");
	//printf("hola%cHola", "OsaS");
	//printf("\n");
	return(0);
}