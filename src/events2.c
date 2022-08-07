/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:11:32 by pcervill          #+#    #+#             */
/*   Updated: 2022/08/06 23:58:13 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_map *map)
{
	int	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
	return (0);
}

void	coins(t_map *map)
{
	map->coin--;
	printf("%sCOGISTE UNA MONEDA, %sTE FALTAN: %d\n%s", GREEN,
		MAGENT, map->coin, NORMAL);
	if (map->coin == 0)
	{
		printf("%sMONEDAS RECOGIDAS, BUSCA LA SALIDA\n%s", BLUE, NORMAL);
	}
}
