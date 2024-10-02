/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:35:34 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/02 13:45:19 by pcervill         ###   ########.fr       */
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
	int	movlast;

	map->prev_x = map->xp;
	map->prev_y = map->yp;
	movlast = map->mov;
	if (keycode == ESC || keycode == ESC_L)
		close_game(map);
	else if (keycode == A || keycode == LEFT || keycode == A_L || keycode == L)
		mov_left(map);
	else if (keycode == D || keycode == RIGHT || keycode == D_L || keycode == R)
		mov_right(map);
	else if (keycode == S || keycode == DOWN || keycode == S_L || keycode == DW)
		mov_down(map);
	else if (keycode == W || keycode == UP || keycode == W_L || keycode == U)
		mov_up(map);
	put_image_player(map, map->xp, map->yp);
	if (map->mov != movlast)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("MOVES Nº: ", 1);
		ft_putstr_fd(CYAN, 1);
		ft_putnbr_fd(map->mov, 1);
		write(1, "\n", 1);
	}
	return (0);
}
