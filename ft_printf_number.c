/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:45:18 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/30 22:16:40 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(int n)
{
	char	*buffer;
	//size_t	len; //TODO: TEMPORAL...
	int		i;

	i = 0;
	buffer = ft_itoa(n);
	while (buffer[i] != '\0')
	{
		write(1,&buffer[i],1);
		i++;
	}
	free(buffer);
	return (i);
}

int	ft_printf_unsigned(int n)
{
	int	i;
	//primero comprobamos que el numero sea positivo
	if (n >= 0)
		i = ft_printf_number(n);
	else
	{
		i = ft_printf_number((int)&n);
	}
	return (i);
}

int	ft_printf_pointer(int n)
{
	int	i;
	
	i = ft_print_hex((int)&n,'x');
	return (i);
}
