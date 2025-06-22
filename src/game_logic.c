/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:42:40 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 17:11:13 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"
#include <mlx.h>

void	print_movements(t_game game)
{
	ft_printf("Moves:%d  🦾🍆🥲\n", game.move);
}

static int	is_valid_move(t_game *game, int x, int y)
{
	if (game->board[x][y] == Wall || (game->board[x][y] == Exit
			&& game->coll > 0))
		return (0);
	if (game->board[x][y] == Exit && game->coll == 0)
		return (2);
	if (game->board[x][y] == Col)
	{
		game->board[x][y] = Floor;
		game->coll--;
	}
	return (1);
}

void	update_sprites(t_game game, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.win, game.floor, game.player_y
		* IMG_SZ, game.player_x * IMG_SZ);
	game.board[game.player_x][game.player_y] = Floor;
	game.board[x][y] = Playa;
	game.player_x = x;
	game.player_y = y;
	mlx_put_image_to_window(game.mlx, game.win, game.playa, y * IMG_SZ, x
		* IMG_SZ);
	print_movements(game);
}

void	move(t_game *game, int dir)
{
	int	player_x;
	int	player_y;
	int	x;
	int	y;
	int	move_status;

	decide_direction(dir, &x, &y);
	player_x = game->player_x + x;
	player_y = game->player_y + y;
	move_status = is_valid_move(game, player_x, player_y);
	if (move_status == 0)
		return ;
	game->move++;
	update_sprites(*game, player_x, player_y);
	game->player_x = player_x;
	game->player_y = player_y;
	if (move_status == 2)
	{
		ft_printf("🍆🍆🍆🍆🍆🍆🍆🍆 YOU WIN!! GG NO PROBLEM 🍆🍆🍆🍆🍆🍆🍆🍆\n");
		close_game(game);
		return ;
	}
}

int	key_handle(int key, t_game *game)
{
	if (key == ESC)
		close_game(game);
	else if (key == UP)
		move(game, 1);
	else if (key == DOWN)
		move(game, 2);
	else if (key == LEFT)
		move(game, 3);
	else if (key == RIGHT)
		move(game, 4);
	return (0);
}
