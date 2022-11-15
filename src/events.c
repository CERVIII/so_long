/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:35:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/11/15 14:26:53 by pcervill         ###   ########.fr       */
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
			map->mov++;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp][map->yp - 1] == 'C')
				coins(map);
			map->map[map->xp][map->yp - 1] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->yp = map->yp - 1;
			map->mov++;
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
			map->mov++;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp][map->yp + 1] == 'C')
				coins(map);
			map->map[map->xp][map->yp + 1] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->yp = map->yp + 1;
			map->mov++;
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
			map->mov++;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp + 1][map->yp] == 'C')
				coins(map);
			map->map[map->xp + 1][map->yp] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->xp = map->xp + 1;
			map->mov++;
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
			map->mov++;
			close_game(map);
		}
		else
		{
			if (map->map[map->xp - 1][map->yp] == 'C')
				coins(map);
			map->map[map->xp - 1][map->yp] = 'P';
			map->map[map->xp][map->yp] = '0';
			map->xp = map->xp - 1;
			map->mov++;
		}
	}
}

int	press(int keycode, t_map *map)
{
	map->prev_x = map->xp;
	map->prev_y = map->yp;
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
//	create_image(map);
	put_image_player(map, map->xp, map->yp);
	printf("%sMOVIMIENTO Nº: %s%d\n%s", YELLOW, CYAN, map->mov, NORMAL);
	return (0);
}
