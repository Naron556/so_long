/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:36:58 by aoperacz          #+#    #+#             */
/*   Updated: 2024/12/13 23:08:35 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_hex(unsigned long n)
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
			res[i++] = (n % 16) + 'a' - 10;
		n /= 16;
	}
	while (--i >= 0)
		write(1, &res[i], 1);
	return (len);
}
