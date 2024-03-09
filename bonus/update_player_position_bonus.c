/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:30:34 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 13:47:21 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	put_img_to_window(t_player *player, void *img, int x, int y)
{
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img, x, y);
}

void	update_player_position_and_render(t_player *player)
{
	if (player->keycode == 2
		&& player->map[player->y][player->x - 1] != '1'
		&& player->map[player->y][player->x - 1] != 'C')
		put_img_to_window(player, player->background_img, (player->x - 1)
			* player->img_width, player->y * player->img_height);
	else if (player->keycode == 0
		&& player->map[player->y][player->x + 1] != '1'
		&& player->map[player->y][player->x + 1] != 'C')
		put_img_to_window(player, player->background_img, (player->x + 1)
			* player->img_width, player->y * player->img_height);
	else if (player->keycode == 13
		&& player->map[player->y - 1][player->x] != '1'
		&& player->map[player->y - 1][player->x] != 'C')
		put_img_to_window(player, player->background_img, player->x
			* player->img_width, (player->y - 1) * player->img_height);
	else if (player->keycode == 1
		&& player->map[player->y + 1][player->x] != '1'
		&& player->map[player->y + 1][player->x] != 'C')
		put_img_to_window(player, player->background_img, player->x
			* player->img_width, (player->y + 1) * player->img_height);
	put_img_to_window(player, player->player_img, player->x
		* player->img_width, player->y * player->img_height);
}

void	initialize_all_animations(t_player *player)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		player->animations[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		player->e_animations[i] = NULL;
		i++;
	}
}
