/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:39:59 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/21 03:18:37 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *arg, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_hex(unsigned long n);
int		ft_hexx(unsigned long n);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_put_u_nbr(unsigned int n);
int		hexlen(unsigned long n);
int		ft_pointer(void *pointer);

#endif