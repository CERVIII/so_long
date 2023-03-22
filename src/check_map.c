/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:38:12 by pcervill          #+#    #+#             */
/*   Updated: 2023/03/21 10:39:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	arg_ok(int argc, char *argv, t_map *map)
{
	int		len;

	map->starg = 1;
	if (argc != 2)
	{
		map->starg = 0;
		printf("%sError\nNo has cargado el mapa\n", RED);
		ft_error("Try ./so_long <name of map>.ber\n", map);
	}
	else
	{
		len = ft_strlen(argv);
		if (ft_strncmp(argv + len - 4, ".ber", 4))
		{
			map->starg = 0;
			ft_error("Error\nSe necesita la extension '.ber'\n", map);
		}
	}
}

void	read_write_fdmap(char *argv, t_map *map)
{
	char	*newstr;
	char	*strmap;
	char	*strmap2;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (!fd || fd == -1)
		ft_error("\nError\nArchivo no encontrado\n", map);
	strmap = ft_strdup("");
	while (1)
	{
		newstr = get_next_line(fd);
		if (!newstr)
			break ;
		strmap2 = ft_strdup(strmap);
		free(strmap);
		strmap = ft_strjoin(strmap2, newstr);
		free(strmap2);
		free(newstr);
	}
	map->map = ft_split(strmap, '\n');
	map->map2 = ft_split(strmap, '\n');
	free(strmap);
}
