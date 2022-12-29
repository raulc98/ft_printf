/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:32:03 by rcabrero          #+#    #+#             */
/*   Updated: 2022/12/29 14:17:57 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_len(uintptr_t n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i ++;
		n = n / 16;
	}
	return (i);
}

void	ft_printf_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_printf_ptr(n / 16);
		ft_printf_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_printf_pointer(unsigned long long n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (n == 0)
		i += write (1, "0", 1);
	else
	{
		ft_printf_ptr(n);
		i += pointer_len(n);
	}
	return (i);
}
