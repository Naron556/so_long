/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:27:19 by aoperacz          #+#    #+#             */
/*   Updated: 2024/12/12 20:29:34 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u_nbr(unsigned int n)
{
	int				i;
	int				j;
	char			res[12];

	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	j = i;
	while (--i >= 0)
		write(1, &res[i], 1);
	return (j);
}
