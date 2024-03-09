/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_movement_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:32:20 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/03 20:19:47 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	right_left_movement(t_player *player, int right_left)
{
	if (right_left == 1)
	{
		player->enemy_x++;
		player->e_keycode = 2;
	}
	else if (right_left == 0)
	{
		player->enemy_x--;
		player->e_keycode = 0;
	}
}

void	up_down_movement(t_player *player, int up_down)
{
	if (up_down == 1)
	{
		player->enemy_y--;
		player->e_keycode = 1;
	}
	else if (up_down == 0)
	{
		player->enemy_y++;
		player->e_keycode = 13;
	}
}

void	up_down_enemies_movement(t_player *player, int direction, int i)
{
	if (direction == 0
		&& (player->map[player->enemies[i].enemy_y]
			[player->enemies[i].enemy_x - 1]) != '1'
		&& (player->map[player->enemies[i].enemy_y]
			[player->enemies[i].enemy_x - 1]) != 'E')
	{
		player->enemies[i].enemy_x--;
		player->enemies[i].keycode = 0;
	}
	else if (direction == 2
		&& (player->map[player->enemies[i].enemy_y]
			[player->enemies[i].enemy_x + 1]) != '1'
		&& (player->map[player->enemies[i].enemy_y]
			[player->enemies[i].enemy_x + 1]) != 'E')
	{
		player->enemies[i].enemy_x++;
		player->enemies[i].keycode = 2;
	}
	else
		player->enemies[i].keycode = -1;
}

void	right_left_enemies_movement(t_player *player, int direction, int i)
{
	if (direction == 1
		&& (player->map[player->enemies[i].enemy_y - 1]
			[player->enemies[i].enemy_x]) != '1'
		&& (player->map[player->enemies[i].enemy_y - 1]
			[player->enemies[i].enemy_x]) != 'E')
	{
		player->enemies[i].enemy_y--;
		player->enemies[i].keycode = 1;
	}
	else if (direction == 3
		&& (player->map[player->enemies[i].enemy_y + 1]
			[player->enemies[i].enemy_x]) != '1'
		&& (player->map[player->enemies[i].enemy_y + 1]
			[player->enemies[i].enemy_x]) != 'E')
	{
		player->enemies[i].enemy_y++;
		player->enemies[i].keycode = 13;
	}
	else
		player->enemies[i].keycode = -1;
}
