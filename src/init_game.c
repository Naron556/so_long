/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:01:00 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 17:15:27 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_details(t_game *game, int rows)
{
	int	y;
	int	x;

	y = -1;
	game->coll = 0;
	game->exit_c = 0;
	while (++y < rows)
	{
		x = -1;
		while (game->board[y][++x])
		{
			if (game->board[y][x] == Playa)
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->board[y][x] == Col)
				game->coll++;
			if (game->board[y][x] == Exit)
				game->exit_c++;
		}
	}
}
