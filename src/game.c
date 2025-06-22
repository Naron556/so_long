/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:22:40 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 17:35:16 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>

static void	flat_fill(char **board, int *freq, int x, int y)
{
	if (board[y][x] == Wall)
		return ;
	if (board[y][x] == 'M')
		return ;
	if (board[y][x] == Col)
		freq[Col]--;
	if (board[y][x] == Exit)
	{
		freq[Exit]--;
		return ;
	}
	board[y][x] = 'M';
	flat_fill(board, freq, x - 1, y);
	flat_fill(board, freq, x + 1, y);
	flat_fill(board, freq, x, y - 1);
	flat_fill(board, freq, x, y + 1);
}

int	flood_fill(char **board, int *freq, int x, int y)
{
	flat_fill(board, freq, x, y);
	return (freq[Col] > 0 || freq[Exit] > 0);
}

int	check_no_texture(t_game game)
{
	if (game.playa == NULL)
		return (1);
	if (game.floor == NULL)
		return (1);
	if (game.col == NULL)
		return (1);
	if (game.wall == NULL)
		return (1);
	if (game.exit == NULL)
		return (1);
	return (0);
}

void	game_printer(t_game g)
{
	int	x;
	int	y;
	int	type;

	y = -1;
	while (++y < g.rows)
	{
		x = -1;
		while (++x < g.columns)
		{
			type = g.board[y][x];
			mlx_put_image_to_window(g.mlx, g.win, g.floor, x * 32, y * 32);
			if (type == Col)
				mlx_put_image_to_window(g.mlx, g.win, g.col, x * 32, y * 32);
			if (type == Playa)
				mlx_put_image_to_window(g.mlx, g.win, g.playa, x * 32, y * 32);
			if (type == Exit)
				mlx_put_image_to_window(g.mlx, g.win, g.exit, x * 32, y * 32);
			if (type == Wall)
				mlx_put_image_to_window(g.mlx, g.win, g.wall, x * 32, y * 32);
		}
	}
}

int	launch_game(char **board, int rows)
{
	t_game	game;
	int		freq_vec[256];

	game.board = copy_board(board, rows);
	load_details(&game, rows);
	freq_vec[Col] = game.coll;
	freq_vec[Exit] = game.exit_c;
	game.rows = rows;
	game.columns = ft_strlen(board[0]);
	if (flood_fill(board, freq_vec, game.player_x, game.player_y))
		return (free_board(board, rows), free_table(game.board), 1);
	game_init(&game);
	if (check_no_texture(game))
		return (free_game(&game), 1);
	free_board(board, rows);
	game.win = mlx_new_window(game.mlx, game.columns * 32, rows * 32, "Comrad");
	game_printer(game);
	mlx_key_hook(game.win, key_handle, &game);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
