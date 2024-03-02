/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:25:33 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:46 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

char	**store_in_2d_array(int fd, t_player *player)
{
	int		y;
	char	*line;
	char	**map;

	y = 0;
	map = malloc(sizeof(char *) * player->map_height);
	if (!map)
		exit(1);
	while (y < player->map_height)
	{
		line = get_next_line(fd);
		map[y] = ft_strdup(line);
		if (!map[y])
			ft_close(player, 1);
		free(line);
		y++;
	}
	return (map);
}

char	**reading_map(t_player *player)
{
	char	**map;
	int		fd;
	int		lines;
	int		rows;

	map = NULL;
	lines = 0;
	rows = 0;
	fd = open(player->map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map not found!!\n", 2);
		ft_close(player, 1);
	}
	map = store_in_2d_array(fd, player);
	return (map);
}
