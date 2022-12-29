/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:45:18 by rcabrero          #+#    #+#             */
/*   Updated: 2022/12/29 14:15:54 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_number(long int n)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = ft_itoa(n);
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		i++;
	}
	free (buffer);
	return (i);
}

int	ft_printf_unsigned(unsigned int n)
{
	int		print_length;
	char	*temp;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		temp = ft_uitoa(n);
		print_length += ft_printf_string(temp);
		free(temp);
	}
	return (print_length);
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
