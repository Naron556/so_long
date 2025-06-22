/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:53:07 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 02:18:54 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <sys/stat.h>

static void	free_getnext(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	read_map(char **board, int *row_count, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i >= MAX_MAP_SIZE || ft_strncmp("\n", line, 2) == 0)
			return (free(line), free_getnext(fd), free_board(board, i), 1);
		remove_newline(&line);
		if (check_valid_elem(line) || ft_strlen(line) > MAX_MAP_SIZE)
			return (free(line), free_getnext(fd), free_board(board, i), 1);
		board[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	*row_count = i;
	return (0);
}

int	cleanup_and_exit(char **board, int rows, const char *msg, int code)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	free_board(board, rows);
	return (code);
}

int	check_ber(char *av)
{
	size_t	len;

	len = ft_strlen(av);
	if (len < 5)
		return (1);
	if (ft_strncmp(av + len - 4, ".ber", 4) != 0)
		return (1);
	return (0);
}

/*
 * Map check for lines length
 * Map check for Square
 * Map check for border
 * Map check for Player x1 Exit x1
 * Map check for at least x1 Collectable
 */
int	main(int argc, char **argv)
{
	char	*board[MAX_MAP_SIZE];
	int		fd;
	int		row_count;

	row_count = 0;
	if (argc != 2)
		return (write(2, "Invalid args\n", 13), 1);
	if (check_ber(argv[1]))
		return (write(2, "Invalid type of file\n", 22), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Cannot open file\n", 17), 1);
	if (read_map(board, &row_count, fd))
		return (cleanup_and_exit(board, row_count, "Invalid map\n", 1));
	if (check_validate(board, row_count))
		return (cleanup_and_exit(board, row_count, "Invalid map\n", 1));
	return (cleanup_and_exit(board, row_count, NULL, 0));
}
