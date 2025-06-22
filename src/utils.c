/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:18:30 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 17:32:34 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>

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

char	**copy_board(char **board, int rows)
{
	char	**copy;
	int		i;

	i = -1;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (copy == NULL)
		return (NULL);
	while (++i < rows)
		copy[i] = ft_strdup(board[i]);
	copy[i] = NULL;
	return (copy);
}

void	free_table(char **board)
{
	int	i;

	i = 0;
	if (board == NULL)
		return ;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	free_game(t_game *game)
{
	if (game->playa != NULL)
		mlx_destroy_image(game->mlx, game->playa);
	if (game->floor != NULL)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->col != NULL)
		mlx_destroy_image(game->mlx, game->col);
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit != NULL)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_table(game->board);
	game = NULL;
}
