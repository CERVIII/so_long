/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:10:57 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/20 13:12:39 by pcervill         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	char	**map2;
	char	*strmap;
	char	*sprite;
	int		starg;
	int		person;
	int		coin;
	int		coin2;
	int		exit;
	int		valid_exit;
	int		xmax;
	int		ymax;
	int		xp;
	int		yp;
	int		prev_x;
	int		prev_y;
	int		w;
	int		h;
	int		mov;
	void	*mlx;
	void	*img;
	void	*mlx_win;
}	t_map;

void	arg_ok(int argc, char *argv, t_map *map);
void	read_write_fdmap(char *argv, t_map *map);
int		check_game_map(t_map *map);
void	init_struct(t_map *map);
void	new_window(t_map *map);
void	create_image(t_map	*map);
int		press(int keycode, t_map *map);
int		close_game(t_map *map);
void	coins(t_map *map);
void	ft_check_validpath(t_map *map, int x, int y);
void	ft_check_path(t_map *map);
int		ft_error(char *error, t_map *map);
void	free_all(t_map *map);
void	put_image_player(t_map *map, int x, int y);

#endif