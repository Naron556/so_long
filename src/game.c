/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:22:40 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 02:31:41 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	game_launch(char **board, int rows)
{
	
	if (flood_fill())
		return (1);
	//ALL the mlx stuff here + drawing things
	return (0);
}
