/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:11:32 by pcervill          #+#    #+#             */
/*   Updated: 2023/09/13 13:11:05 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error(char *error, t_map *map)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd(NORMAL, 1);
	if (map->starg == 1)
		free_all(map);
	exit(EXIT_FAILURE);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	i = 0;
}

int	close_game(t_map *map)
{
	free_all(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
	return (0);
}

void	coins(t_map *map)
{
	map->coin--;
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("YOU CAUGHT A COIN, ", 1);
	ft_putstr_fd(MAGENT, 1);
	ft_putstr_fd("REMAINING COINS: ", 1);
	ft_putnbr_fd(map->coin, 1);
	write(1, "\n", 1);
	if (map->coin == 0)
	{
		ft_putstr_fd(BLUE, 1);
		ft_putendl_fd("COLLECTED COINS, LOOK FOR THE EXIT", 1);
	}
}
