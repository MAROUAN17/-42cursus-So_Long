/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:03:20 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:56:43 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int	first_line_and_last(char **map, int y, int width)
{
	int	x;
	int	check;

	x = 0;
	check = 0;
	while (x <= width && map[y][x] == '1')
		x++;
	if (map[y][x] && map[y][x] != '\n' && x <= width && map[y][x] != '1')
		check = 1;
	return (check);
}

int	other_lines(char **map, int y, int width)
{
	int	check;
	int	x;

	x = 0;
	check = 0;
	if (map[y][x] != '1' || map[y][width - 1] != '1')
		check = 1;
	return (check);
}

int	check_walls(char **map, int height, int width)
{
	int	check;
	int	x;
	int	y;

	check = 0;
	x = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		if (y == 0 || y == height - 1)
			check = first_line_and_last(map, y, width);
		else
			check = other_lines(map, y, width);
		y++;
	}
	return (check);
}

int	check_rectangular_map(char **map, int height, int width)
{
	int	check;
	int	counter;
	int	x;
	int	y;

	check = 0;
	counter = 0;
	x = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		counter = 0;
		while (map[y][counter] && map[y][counter] != '\n')
			counter++;
		if (counter != width)
		{
			check = 1;
			break ;
		}
		y++;
	}
	return (check);
}

int	parsing_map(t_player *player)
{
	int	check;
	int	counter;
	int	x;
	int	y;

	counter = 0;
	check = 0;
	x = 0;
	y = 0;
	if (player->map_height > player->map_width
		|| player->map_height == player->map_width || !player->map[0][0]
		|| check_rectangular_map(player->map, player->map_height,
		player->map_width) || check_walls(player->map, player->map_height,
		player->map_width) || check_collectible(player) || check_exits(player)
		|| check_start(player) || check_reachable_collectibles(player) ||
		check_reachable_exits(player) || path_check(player) ||
		player->map_width > 5120 || player->map_height > 2880)
		check = 1;
	return (check);
}
