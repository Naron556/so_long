/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:07:52 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/22 17:15:37 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG_H)
# define SO_LONG_H

# define MAX_MAP_SIZE 30

# include <stdlib.h>

# define Playa_t "textures/ship_up.xpm"
# define Wall_t "textures/wall.xpm"
# define Floor_t "textures/background.xpm"
# define Col_t "textures/collectable.xpm"
# define Exit_t "textures/exit.xpm"

# define IMG_SZ 32

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef enum e_game_elems
{
	Playa = 'P',
	Wall = '1',
	Floor = '0',
	Col = 'C',
	Exit = 'E',
}			t_elems;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	void	*playa;
	void	*wall;
	void	*floor;
	void	*col;
	void	*exit;

	int		player_x;
	int		player_y;
	int		coll;
	int		playa_c;
	int		exit_c;

	char	**board;
	int		rows;
	int		columns;
	int		move;
}			t_game;

int			check_square(char **board, int count);
int			check_valid_elem(char *line);
int			check_walls(char **board, int rows);
int			count_chars(char **board, int *col, int rows);
int			check_validate(char **board, int rows);
void		free_board(char **board, int rows);
int			is_game_elem(char c);
void		remove_newline(char **s);
char		**copy_board(char **board, int rows);
void		free_table(char **board);
void		load_details(t_game *game, int rows);
void		free_game(t_game *game);
void		game_printer(t_game game);
void		print_movements(t_game game);
int			launch_game(char **board, int rows);
void		game_init(t_game *game);
int			key_handle(int key, t_game *game);
int			close_game(t_game *game);
void		decide_direction(int dir, int *x, int *y);
#endif // SO_LONG_H
