/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:40:09 by aoperacz          #+#    #+#             */
/*   Updated: 2024/12/13 23:11:54 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(const char *arg, va_list argument)
{
	int	count;

	count = 0;
	if (*arg == 'c')
		count += ft_putchar_fd(va_arg(argument, int), 1);
	else if (*arg == 's')
		count += ft_putstr_fd(va_arg(argument, char *), 1);
	else if (*arg == 'p')
		count += ft_pointer(va_arg(argument, void *));
	else if (*arg == 'd' || *arg == 'i')
		count += ft_putnbr_fd(va_arg(argument, int), 1);
	else if (*arg == 'u')
		count += ft_put_u_nbr(va_arg(argument, unsigned int));
	else if (*arg == 'x')
		count += ft_hex(va_arg(argument, unsigned int));
	else if (*arg == 'X')
		count += ft_hexx(va_arg(argument, unsigned int));
	else if (*arg == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *arg, ...)
{
	int		count;
	va_list	list;

	va_start(list, arg);
	count = 0;
	while (*arg)
	{
		if (*arg == '%')
		{
			arg++;
			count += format(arg, list);
		}
		else
			count += ft_putchar_fd(*arg, 1);
		arg++;
	}
	return (count);
}
