/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:52:42 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 17:09:48 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	game_init(t_game *game)
{
	int	x;
	int	y;

	game->win = NULL;
	game->mlx = mlx_init();
	game->playa = mlx_xpm_file_to_image(game->mlx, Playa_t, &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx, Wall_t, &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, Floor_t, &x, &y);
	game->col = mlx_xpm_file_to_image(game->mlx, Col_t, &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, Exit_t, &x, &y);
	game->move = 0;
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

void	decide_direction(int dir, int *x, int *y)
{
	if (dir == 3)
	{
		*x = 0;
		*y = -1;
	}
	if (dir == 4)
	{
		*x = 0;
		*y = 1;
	}
	if (dir == 1)
	{
		*x = -1;
		*y = 0;
	}
	if (dir == 2)
	{
		*x = 1;
		*y = 0;
	}
}

void	render_map(t_game *game, int x, int y)
{
	int	type;

	type = game->board[y / IMG_SZ][x / IMG_SZ];
	mlx_put_image_to_window(game->mlx, game->win, game->floor, x, y);
	if (type == Wall)
		mlx_put_image_to_window(game->mlx, game->win, game->col, x, y);
	else if (type == Playa)
		mlx_put_image_to_window(game->mlx, game->win, game->playa, x, y);
	else if (type == Exit)
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
	else if (type == Wall)
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
}
