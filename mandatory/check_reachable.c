/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reachable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:51:07 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 19:31:13 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	flood_fill_c(t_player *player, t_point cur,
	int *p_counter, char to_check)
{
	if (cur.y >= player->map_height || cur.x >= player->map_width || cur.x < 0
		|| cur.y < 0 || player->map_test[cur.y][cur.x] == '1'
		|| player->map_test[cur.y][cur.x] == 'E')
		return ;
	if (player->map_test[cur.y][cur.x] == to_check)
		(*p_counter)++;
	player->map_test[cur.y][cur.x] = '1';
	flood_fill_c(player, (t_point){cur.x - 1, cur.y}, p_counter, to_check);
	flood_fill_c(player, (t_point){cur.x + 1, cur.y}, p_counter, to_check);
	flood_fill_c(player, (t_point){cur.x, cur.y + 1}, p_counter, to_check);
	flood_fill_c(player, (t_point){cur.x, cur.y - 1}, p_counter, to_check);
}

void	flood_fill_e(t_player *player, t_point cur,
	int *p_counter, char to_check)
{
	if (cur.y >= player->map_height || cur.x >= player->map_width || cur.x < 0
		|| cur.y < 0 || player->map_test[cur.y][cur.x] == '1')
		return ;
	if (player->map_test[cur.y][cur.x] == to_check)
		(*p_counter)++;
	player->map_test[cur.y][cur.x] = '1';
	flood_fill_e(player, (t_point){cur.x - 1, cur.y}, p_counter, to_check);
	flood_fill_e(player, (t_point){cur.x + 1, cur.y}, p_counter, to_check);
	flood_fill_e(player, (t_point){cur.x, cur.y + 1}, p_counter, to_check);
	flood_fill_e(player, (t_point){cur.x, cur.y - 1}, p_counter, to_check);
}

int	check_reachable_collectibles(t_player *player)
{
	t_point	size;
	t_point	player_start;
	int		check;
	int		collectibles;

	collectibles = 0;
	check = 0;
	player_start.x = player->x;
	player_start.y = player->y;
	size.x = player->map_width;
	size.y = player->map_height;
	player->map_test = reading_map(player, player->map_path);
	flood_fill_c(player, player_start, &collectibles, 'C');
	if (collectibles == player->total_collectibles)
		check = 0;
	else
		check = 1;
	free_map(player->map_test, player->map_height);
	return (check);
}

int	check_reachable_exits(t_player *player)
{
	t_point	size;
	t_point	player_start;
	int		check;
	int		exits;

	exits = 0;
	check = 0;
	player_start.x = player->x;
	player_start.y = player->y;
	size.x = player->map_width;
	size.y = player->map_height;
	player->map_test = reading_map(player, player->map_path);
	flood_fill_e(player, player_start, &exits, 'E');
	if (exits == count_a_tile(player, 'E'))
		check = 0;
	else
		check = 1;
	free_map(player->map_test, player->map_height);
	return (check);
}
