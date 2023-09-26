/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:22:37 by pcervill          #+#    #+#             */
/*   Updated: 2023/09/26 15:41:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* static void	leaks(void)
{
	system("leaks -q so_long");
} atexit(leaks); */

void	init_struct(t_map *map)
{
	map->person = 0;
	map->coin = 0;
	map->exit = 0;
	map->mov = 0;
	map->sprp = PJR;
	printf("%s\n", map->sprp);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	arg_ok(argc, argv[1], &map);
	read_write_fdmap(argv[1], &map);
	if (map.map[0] == NULL)
		ft_error("Error\nNo valid map\n", &map);
	if (!check_game_map(&map))
		exit (1);
	ft_check_validpath(&map, map.xp, map.yp);
	ft_check_path(&map);
	new_window(&map);
	mlx_hook(map.mlx_win, 2, (1L << 0), press, &map);
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd("LOADING...\n", 1);
	mlx_hook(map.mlx_win, 17, 0, close_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
