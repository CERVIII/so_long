/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:22:37 by pcervill          #+#    #+#             */
/*   Updated: 2022/09/14 14:41:15 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	leaks(void)
{
	system("leaks -q so_long");
}

void	init_struct(t_map *map)
{
	map->person = 0;
	map->coin = 0;
	map->exit = 0;
	map->mov = 0;
}

int	main(int argc, char *argv[])
{
	t_map	map;

	atexit(leaks);
	if (arg_ok(argc, argv[1]) == 0)
	{
		printf("%sERROR:\nArgumento invalido o mal nombrado\n%s", RED, NORMAL);
		return (0);
	}
	read_write_fdmap(argv[1], &map);
	if (map.map[0] == NULL)
	{
		printf("%sERROR\nMapa Invalido\n%s", RED, NORMAL);
		return (0);
	}
	if (!check_game_map(&map))
		return (0);
	new_window(&map);
	mlx_hook(map.mlx_win, 2, (1L << 0), press, &map);
	printf("%sCARGANDO...\n%s", YELLOW, NORMAL);
	mlx_hook(map.mlx_win, 17, 0, close_game, &map);
	mlx_loop(map.mlx);
}
