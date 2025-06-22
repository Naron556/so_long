/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:53:27 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 02:12:19 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_square(char **board, int count)
{
	size_t	len;
	int		i;

	len = ft_strlen(board[0]);
	i = 0;
	while (i < count)
		if (ft_strlen(board[i++]) != len)
			return (1);
	return (0);
}

int	check_valid_elem(char *line)
{
	int	i;

	i = -1;
	if (line == NULL)
		return (1);
	while (line[++i])
		if (!is_game_elem(line[i]))
			return (1);
	return (0);
}

int	check_walls(char **board, int rows)
{
	int	len;
	int	i;

	len = ft_strlen(board[0]);
	i = 0;
	while (i < len)
		if (board[0][i] != Wall || board[rows - 1][i++] != Wall)
			return (1);
	i = 1;
	while (i < rows - 1)
		if (board[i][0] != Wall || board[i++][len - 1] != Wall)
			return (1);
	return (0);
}

int	count_chars(char **board, int *col, int rows)
{
	int	i;
	int	p;
	int	e;
	int	j;

	i = -1;
	p = 0;
	e = 0;
	while (++i < rows)
	{
		j = -1;
		while (board[i][++j])
		{
			if (board[i][j] == Playa)
				p++;
			else if (board[i][j] == Exit)
				e++;
			else if (board[i][j] == Col)
				(*col)++;
		}
	}
	return (p == 1 && e == 1 && *col >= 1);
}

int	check_validate(char **board, int rows)
{
	int	col;

	col = 0;
	if (rows < 3)
		return (1);
	if (check_square(board, rows) || check_walls(board, rows))
		return (1);
	if (!count_chars(board, &col, rows))
		return (1);
	return (0);
}
