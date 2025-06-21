/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:20:44 by aoperacz          #+#    #+#             */
/*   Updated: 2024/12/13 22:58:22 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexx(unsigned long n)
{
	int		len;
	int		i;
	char	res[25];

	len = hexlen(n);
	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n != 0)
	{
		if ((n % 16) < 10)
			res[i++] = (n % 16) + '0';
		else
			res[i++] = (n % 16) + 'A' - 10;
		n /= 16;
	}
	while (--i >= 0)
		write(1, &res[i], 1);
	return (len);
}
