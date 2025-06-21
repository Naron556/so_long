/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:53:07 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/21 03:22:08 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>

int	count_chars(char **board, int *col)
{
	int	i;
	int	p;
	int	e;
	int	j;

	i = -1;
	p = 0;
	e = 0;
	while (board[++i])
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

int	check_map(char *game_board[30])
{
	size_t	old_len;

	old_len = ft_strlen(*game_board);
	game_board++;
	while (*game_board)
	{
		if (old_len != ft_strlen(*game_board))
			return (1);
		else
			old_len = ft_strlen(*game_board);
		game_board++;
	}
	return (0);
}

/*
 * Map check for lines length
 * Map check for Square
 * Map check for border
 * Map check for Player x1 Exit x1
 * Map check for at least x1 Collectable
 */
int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;
	int		i;
	char	*board[30];
	int		c;

	if (argc != 2)
		return (write(2, "Invalid args\n", 13), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Cannot open file\n", 17), 1);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		remove_newline(&line);
		if (check_valid_elem(line) || ft_strlen(line) > 30 || i >= 30)
			return (free(line), 1);
		board[i++] = ft_strdup(line);
		free(line);
	}
	if (i < 3 || check_square(board, i) || check_walls(board, i)
		|| count_chars(board, &c))
		return (write(2, "Invalid map\n", 12), 1);
	return (0);
}
