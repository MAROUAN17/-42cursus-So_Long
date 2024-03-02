/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:10:12 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:31:14 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

char	**store_in_2d_array(int fd, t_player *player)
{
	int		y;
	char	*line;
	char	**map;

	y = 0;
	map = malloc(sizeof(char *) * player->map_height);
	if (!map)
		ft_close(player, 1);
	while (y < player->map_height)
	{
		line = get_next_line(fd);
		map[y] = ft_strdup(line);
		if (!line || !map[y])
			ft_close(player, 1);
		free(line);
		y++;
	}
	return (map);
}

char	**reading_map(t_player *player, char *path)
{
	char	**map;
	int		fd;

	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map not found!!\n", 2);
		ft_close(player, 1);
	}
	map = store_in_2d_array(fd, player);
	return (map);
}
