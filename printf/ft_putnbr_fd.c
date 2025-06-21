/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:58:11 by aoperacz          #+#    #+#             */
/*   Updated: 2024/12/14 14:19:47 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				i;
	int				j;
	char			res[13];

	i = 0;
	if (n == 0)
		res[i++] = '0';
	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)(n);
	while (num > 0)
	{
		res[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	if (n < 0)
		res[i++] = '-';
	j = i;
	while (--i >= 0)
		write(fd, &res[i], 1);
	return (j);
}
