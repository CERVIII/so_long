/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:26:35 by pcervill          #+#    #+#             */
/*   Updated: 2023/09/13 11:04:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_exit(t_map *map, int x, int y)
{
		map->map2[x][y] = '1';
		map->valid_exit = 1;
}

void	ft_check_validpath(t_map *map, int x, int y)
{
	char	*p;

	p = &map->map2[x][y];
	if (*p == 'E')
		ft_check_exit(map, x, y);
	if (*p != '1')
	{
		if (*p == 'C')
			map->coin2--;
		*p = '.';
		if (map->map2[x][y + 1] != '1' &&
			map->map2[x][y + 1] != '.')
			ft_check_validpath(map, x, y + 1);
		if (map->map2[x][y - 1] != '1' &&
			map->map2[x][y - 1] != '.')
			ft_check_validpath(map, x, y - 1);
		if (map->map2[x - 1][y] != '1' &&
			map->map2[x - 1][y] != '.')
			ft_check_validpath(map, x - 1, y);
		if (map->map2[x + 1][y] != '1' &&
			map->map2[x + 1][y] != '.')
			ft_check_validpath(map, x + 1, y);
	}
}

void	ft_check_path(t_map *map)
{
	int	i;

	i = 0;
	while (map->map2[i])
	{
		free(map->map2[i]);
		i++;
	}
	free(map->map2);
	if (map->coin2 != 0 || map->valid_exit != 1)
		ft_error("\nError\nNo valid path.\n", map);
}
