/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:45:07 by pcervill          #+#    #+#             */
/*   Updated: 2022/06/08 18:30:13 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*condition_print(int x, int y, t_map *map)
{
	map->sprite = "";
	if (map->map[x][y] == '1')
		return (map->sprite = WL);
	else if (map->map[x][y] == 'C')
		return (map->sprite = CO);
	else if (map->map[x][y] == 'P')
		return (map->sprite = PJ);
	else if (map->map[x][y] == 'E')
		return (map->sprite = EX);
	else if (map->map[x][y] == '0')
		return (map->sprite = FL);
	return (NULL);
}

static void	put_image(t_map *map, int x, int y)
{
	map->img = mlx_xpm_file_to_image(map->mlx,
			condition_print(x, y, map), &map->w, &map->h);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->img, y * 56, x * 56);
	mlx_destroy_image(map->mlx, map->img);
}

void	create_image(t_map	*map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			map->img = mlx_xpm_file_to_image(map->mlx, FL,
					&map->w, &map->h);
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->img, y * 56, x * 56);
			mlx_destroy_image(map->mlx, map->img);
			put_image(map, x, y);
			y++;
		}
		x++;
	}
}

void	new_window(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, (map->ymax) * 56,
			(map->xmax) * 56, "so_long");
	create_image(map);
}

/* static void	put_image(t_map *map, t_win *win, int x, int y)
{
	win->img = mlx_xpm_file_to_image(win->mlx,
			condition_print(x, y, map), &map->w, &map->h);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->img, y * 56, x * 56);
} */

/* void	create_image(t_map	*map, t_win *win)
{
	int	x;
	int	y;

	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			win->img = mlx_xpm_file_to_image(win->mlx, FL,
					&map->w, &map->h);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->img, y * 56, x * 56);
			put_image(map, win, x, y);
			y++;
		}
		x++;
	}
} */

/* void	new_window(t_map *map, t_win *win)
{
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, (map->ymax + 1) * 56,
			(map->xmax + 1) * 56, "so_long");
	create_image(map, win);
} */
