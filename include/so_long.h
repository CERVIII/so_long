/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:10:57 by pcervill          #+#    #+#             */
/*   Updated: 2022/08/06 23:57:08 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl/mlx.h"
# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define PJ "./Sprites/Pacman_HD.xpm"
# define CO "./Sprites/coin.xpm"
# define EX "./Sprites/portal_close.xpm"
# define FL "./Sprites/floor1.xpm"
# define WL "./Sprites/wall.xpm"

# define NORMAL  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENT  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define UP 126
# define ESC 53

/* typedef struct s_win
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
}	t_win; */

typedef struct s_map
{
	char	**map;
	char	*strmap;
	char	*sprite;
	int		person;
	int		coin;
	int		exit;
	int		xmax;
	int		ymax;
	int		xp;
	int		yp;
	int		w;
	int		h;
	int		mov;
	void	*mlx;
	void	*img;
	void	*mlx_win;
}	t_map;

int		arg_ok(int argc, char *argv);
void	read_write_fdmap(char *argv, t_map *map);
int		check_game_map(t_map *map);
void	init_struct(t_map *map);
void	new_window(t_map *map);
void	create_image(t_map	*map);
int		press(int keycode, t_map *map);
int		close_game(t_map *map);
void	coins(t_map *map);

/* int		arg_ok(int argc, char *argv);
void	read_write_fdmap(char *argv, t_map *map);
int		check_game_map(t_map *map);
void	init_struct(t_map *map);
void	new_window(t_map *map, t_win *win);
void	create_image(t_map	*map, t_win *win);
int		press(int keycode, t_map *map, t_win *win); */

#endif