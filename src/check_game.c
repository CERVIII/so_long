/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:40 by pcervill          #+#    #+#             */
/*   Updated: 2022/08/07 00:46:48 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	cont_sprite(t_map *map)
{
	int	x;
	int	y;

	init_struct(map);
	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (map->map[x][y] == 'C')
				map->coin++;
			else if (map->map[x][y] == 'P')
			{
				map->xp = x;
				map->yp = y;
				map->person++;
			}
			else if (map->map[x][y] == 'E')
				map->exit++;
			y++;
		}
		x++;
	}
}

static int	check_char(t_map *map)
{
	int		x;
	int		y;
	char	**aux;

	aux = map->map;
	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (aux[x][y] != '1' && aux[x][y] != '0' && aux[x][y] != 'P' &&
				aux[x][y] != 'C' && aux[x][y] != 'E')
			{
				printf("%s\nERROR\nEl mapa contiene carácteres invalidos\n",
					RED);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

static int	check_borde(t_map *map)
{
	int		x;
	int		y;
	char	**aux;

	aux = map->map;
	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (aux[0][y] != '1' || aux[map->xmax - 1][y] != '1' ||
				aux[x][0] != '1' || aux[x][map->ymax - 1] != '1')
			{
				printf("%s\nERROR\nEl mapa no está bordeado correctamente\n",
					RED);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

static int	check_size_map(t_map *map)
{
	char	**aux;

	aux = map->map;
	map->ymax = ft_strlen(aux[0]);
	map->xmax = 0;
	while (aux[map->xmax] && map->ymax == (int) ft_strlen(aux[map->xmax]))
		map->xmax++;
	if (aux[map->xmax])
		printf("%s\nERROR\nDiferente tamaño de lineas\n",
			RED);
	return (!(aux[map->xmax]));
}

int	check_game_map(t_map *map)
{
	if (check_size_map(map) == 0)
		return (0);
	cont_sprite(map);
	if (check_borde(map) != 1)
		return (0);
	if (check_char(map) != 1)
		return (0);
	if (map->coin < 1 || map->exit < 1 || map->person < 1)
	{
		printf("%s\nERROR\nLa cantidad de E, P y/o C es incorrecta\n",
			RED);
		return (0);
	}
	return (1);
}
