/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:15:43 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:23:44 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	updating_player_render(t_player *player)
{
	if (player->keycode == 2
		&& player->map[player->y][player->x - 1] != '1'
		&& player->map[player->y][player->x - 1] != 'E')
		put_img_to_window(player, player->background, (player->x - 1)
			* player->img_width, (player->y * player->img_height));
	else if (player->keycode == 0
		&& player->map[player->y][player->x + 1] != '1'
		&& player->map[player->y][player->x + 1] != 'E')
		put_img_to_window(player, player->background, (player->x + 1)
			* player->img_width, (player->y * player->img_height));
	else if (player->keycode == 1
		&& player->map[player->y - 1][player->x] != '1'
		&& player->map[player->y - 1][player->x] != 'E')
		put_img_to_window(player, player->background, (player->x
				* player->img_width), (player->y - 1) * player->img_height);
	else if (player->keycode == 13
		&& player->map[player->y + 1][player->x] != '1'
		&& player->map[player->y + 1][player->x] != 'E')
		put_img_to_window(player, player->background, (player->x
				* player->img_width), (player->y + 1) * player->img_height);
	put_img_to_window(player, player->player, player->x
		* player->img_width, player->y * player->img_height);
}
