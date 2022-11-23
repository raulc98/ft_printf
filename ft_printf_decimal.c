/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:45:18 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/23 20:27:58 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library/ft_printf.h"
#include "Library/libft.h"

void	ft_printf_float(double d)
{
	char	*buffer;
	size_t	len;
	int		i;

	len = doubleLen(d);
	//TODO: llamar memcpy...
	//ft_memcpy(buffer,d,len ++);
	i = 0;
	while (buffer[i] != '\0')
	{
		write(1,&buffer[i],1);
		i++;
	}
}

size_t	doubleLen(double d)
{
	size_t len;
	double aux;

	aux = d;
	len = 0;
	//primero llamamos a...
	while(d / 10 != 0)
	{
		aux = aux * 10;
		len ++;
	}
	return len;
}

