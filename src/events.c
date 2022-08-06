/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:35:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/06/08 17:39:01 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mov_left(t_map *map)
{
	if (map->map[map->xp][map->yp - 1] != '1' &&
		!(map->coin != 0 && map->map[map->xp][map->yp - 1] == 'E'))
	{
		if (map->map[map->xp][map->yp - 1] == 'E')
		{
			map->map[map->xp][map->yp - 1] = 'E';
			map->map[map->xp][map->yp] = '0';
			map->yp = map->yp - 1;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp][map->yp - 1] == 'C')
				coins(map);
			map->map[map->xp][map->yp - 1] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->yp = map->yp - 1;
		}
	}
}

void	mov_right(t_map *map)
{
	if (map->map[map->xp][map->yp + 1] != '1' &&
		!(map->coin != 0 && map->map[map->xp][map->yp + 1] == 'E'))
	{
		if (map->map[map->xp][map->yp + 1] == 'E')
		{
			map->map[map->xp][map->yp + 1] = 'E';
			map->map[map->xp][map->yp] = '0';
			map->yp = map->yp + 1;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp][map->yp + 1] == 'C')
				coins(map);
			map->map[map->xp][map->yp + 1] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->yp = map->yp + 1;
		}
	}
}

void	mov_down(t_map *map)
{
	if (map->map[map->xp + 1][map->yp] != '1' &&
		!(map->coin != 0 && map->map[map->xp + 1][map->yp] == 'E'))
	{
		if (map->map[map->xp + 1][map->yp] == 'E')
		{
			map->map[map->xp + 1][map->yp] = 'E';
			map->map[map->xp][map->yp] = '0';
			map->xp = map->xp + 1;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp + 1][map->yp] == 'C')
				coins(map);
			map->map[map->xp + 1][map->yp] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->xp = map->xp + 1;
		}
	}
}

void	mov_up(t_map *map)
{
	if (map->map[map->xp - 1][map->yp] != '1' &&
		!(map->coin != 0 && map->map[map->xp - 1][map->yp] == 'E'))
	{
		if (map->map[map->xp - 1][map->yp] == 'E')
		{
			map->map[map->xp - 1][map->yp] = 'E';
			map->map[map->xp][map->yp] = '0';
			map->xp = map->xp - 1;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp - 1][map->yp] == 'C')
				coins(map);
			map->map[map->xp - 1][map->yp] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->xp = map->xp - 1;
		}
	}
}

int	press(int keycode, t_map *map)
{
	if (keycode == ESC)
		close_game(map);
	else if (keycode == A || keycode == LEFT)
		mov_left(map);
	else if (keycode == D || keycode == RIGHT)
		mov_right(map);
	else if (keycode == S || keycode == DOWN)
		mov_down(map);
	else if (keycode == W || keycode == UP)
		mov_up(map);
	create_image(map);
	map->mov++;
	printf("%sMOVIMIENTO Nº: %s%d\n%s", YELLOW, CYAN, map->mov, NORMAL);
	return (0);
}

/* int	press(int keycode, t_map *map, t_win *win)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		close_game(map);
	if (keycode == A || keycode == LEFT)
	{
		mov_left(map);
	}
	else if (keycode == S || keycode == DOWN)
		mov_down();
	else if (keycode == D || keycode == RIGHT)
		mov_up();
	else if (keycode == W || keycode == UP)
		mov_rigth();
	create_image(map, win);
	return (0);
} */
