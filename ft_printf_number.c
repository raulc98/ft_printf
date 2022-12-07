/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:45:18 by rcabrero          #+#    #+#             */
/*   Updated: 2022/12/07 15:02:42 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_number(long int n)
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
	long int	i;
	if (n >= 0)
		i = ft_printf_number(n);
	else
	{
		printf("N es igual a: %i\n",n);
		i = n * -1;
		printf("x es igual a: %li\n",i);
		//char *prueba = (char *)i;
		printf("N es igual a: %li\n",i);
		ft_uitoa(n);
	}
	return (i);
}

char	*ft_uitoa(unsigned long int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}