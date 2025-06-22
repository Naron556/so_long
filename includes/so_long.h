/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:07:52 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 01:56:22 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG_H)
# define SO_LONG_H

# define MAX_MAP_SIZE 30

# include <stdlib.h>

typedef enum e_game_elems
{
	Playa = 'P',
	Wall = '1',
	Floor = '0',
	Col = 'C',
	Exit = 'E',
}		t_elems;

int		check_square(char **board, int count);
int		check_valid_elem(char *line);
int		check_walls(char **board, int rows);
int		count_chars(char **board, int *col, int rows);
int		check_validate(char **board, int rows);
void	free_board(char **board, int rows);
int		is_game_elem(char c);
void	remove_newline(char **s);
#endif // SO_LONG_H
