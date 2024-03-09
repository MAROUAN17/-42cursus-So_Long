/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:03:20 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/05 17:01:33 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int	first_line_and_last(t_player *player, int y)
{
	int	x;
	int	check;

	x = 0;
	check = 0;
	while (x <= player->map_width && player->map[y][x] == '1')
		x++;
	if (player->map[y][x] && x <= player->map_width
		&& player->map[y][x] != '1')
		check = 1;
	return (check);
}

int	other_lines(t_player *player, int y)
{
	int	check;
	int	x;

	x = 0;
	check = 0;
	while (x <= player->map_width && (player->map[y][x] == '1'
		|| player->map[y][x] == '0' || player->map[y][x] == 'E'
		|| player->map[y][x] == 'P' || player->map[y][x] == 'C'))
	{
		if ((x == 0 || x == player->map_width - 1) && player->map[y][x] != '1')
		{
			check = 1;
			return (check);
		}
		x++;
	}
	if (player->map[y][x] && x <= player->map_width
		&& player->map[y][x] != '1' && player->map[y][x] != '0'
		&& player->map[y][x] != 'E' && player->map[y][x] != 'P'
		&& player->map[y][x] != 'C')
		check = 1;
	return (check);
}

int	check_walls(t_player *player)
{
	int	check;
	int	x;
	int	y;

	check = 0;
	x = 0;
	y = 0;
	while (y < player->map_height)
	{
		x = 0;
		if (y == 0 || y == player->map_height - 1)
		{
			check = first_line_and_last(player, y);
			if (check)
				return (check);
		}
		else
		{
			check = other_lines(player, y);
			if (check)
				return (check);
		}
		y++;
	}
	return (check);
}

int	check_rectangular_map(t_player *player)
{
	int	check;
	int	counter;
	int	x;
	int	y;

	check = 0;
	counter = 0;
	x = 0;
	y = 0;
	while (y < player->map_height)
	{
		x = 0;
		counter = 0;
		while (player->map[y][counter] && player->map[y][counter] != '\n')
			counter++;
		if (counter != player->map_width)
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
	if (!player->map[0][0] || check_rectangular_map(player)
		|| check_walls(player) || check_collectible(player)
		|| check_exits(player) || check_start(player)
		|| check_reachable_collectibles(player) ||
		check_reachable_exits(player) || path_check(player) ||
		player->map_width > (5120 / player->img_width)
		|| player->map_height > (2880 / player->img_height))
		check = 1;
	return (check);
}
