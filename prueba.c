/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:33:14 by rcabrero          #+#    #+#             */
/*   Updated: 2022/11/10 19:45:35 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	double x = 9.88873;
	printf ("Double es igual a... : %f\n", x);
	char * i = itoa(x);
	printf ("i es igual a... : %s\n", i);
	
}