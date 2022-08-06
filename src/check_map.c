/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:38:12 by pcervill          #+#    #+#             */
/*   Updated: 2022/05/31 12:24:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	arg_ok(int argc, char *argv)
{
	return ((argc == 2 && ft_strcmp(ft_strrchr(argv, '.'), ".ber") == 0));
}

void	read_write_fdmap(char *argv, t_map *map)
{
	char	*newstr;
	char	*strmap;
	char	*strmap2;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (!fd)
		return ;
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
	free(strmap);
}
