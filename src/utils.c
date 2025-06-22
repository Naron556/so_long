/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:18:30 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 01:06:59 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	is_game_elem(char c)
{
	return (c == Playa || c == Wall || c == Floor || c == Exit || c == Col);
}

void	remove_newline(char **s)
{
	int	len;

	len = ft_strlen(*s);
	if (len > 0 && (*s)[len - 1] == '\n')
		(*s)[len - 1] = '\0';
}
