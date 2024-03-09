/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animating_enemies_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:54:45 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 10:53:41 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	n_enemy_get_animation_images(t_player *player, int i)
{
	player->enemies[i].e_animations[0]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
			"../textures/enemy/enemy 1.xpm",
			&player->img_width, &player->img_height);
	player->enemies[i].e_animations[1]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
			"../textures/enemy/enemy 2.xpm",
			&player->img_width, &player->img_height);
	player->enemies[i].e_animations[2]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
			"../textures/enemy/enemy 3.xpm",
			&player->img_width, &player->img_height);
	player->enemies[i].e_animations[3]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
			"../textures/enemy/enemy 4.xpm",
			&player->img_width, &player->img_height);
	player->enemies[i].e_animations[4]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
			"../textures/enemy/enemy 5.xpm",
			&player->img_width, &player->img_height);
	player->enemies[i].e_animations[5]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
			"../textures/enemy/enemy 6.xpm",
			&player->img_width, &player->img_height);
}

void	enemies_animation(t_player *player, int x, int y, int i)
{
	static int	j;

	put_img_to_window(player, player->background_img,
		player->enemies[i].enemy_x * player->img_width,
		player->enemies[i].enemy_y * player->img_height);
	if (player->enemies[i].keycode == 2)
		put_img_to_window(player, player->background_img,
			((player->enemies[i].enemy_x - 1) * player->img_width),
			player->enemies[i].enemy_y * player->img_height);
	else if (player->enemies[i].keycode == 0)
		put_img_to_window(player, player->background_img,
			((player->enemies[i].enemy_x + 1) * player->img_width),
			player->enemies[i].enemy_y * player->img_height);
	else if (player->enemies[i].keycode == 1)
		put_img_to_window(player, player->background_img,
			player->enemies[i].enemy_x * player->img_width,
			((player->enemies[i].enemy_y + 1) * player->img_height));
	else if (player->enemies[i].keycode == 13)
		put_img_to_window(player, player->background_img,
			player->enemies[i].enemy_x * player->img_width,
			((player->enemies[i].enemy_y - 1) * player->img_height));
	put_img_to_window(player, player->enemies[i].e_animations[j], x, y);
	j++;
	if (j == 5)
		j = 0;
}

void	enemies_movements(t_player *player, int i)
{
	static int	direction;

	direction = rand() % 4;
	if (direction == 0 || direction == 2)
		up_down_enemies_movement(player, direction, i);
	else if (direction == 1 || direction == 3)
		right_left_enemies_movement(player, direction, i);
}

void	enemy_animations_steps(t_player *player, int i, int counter)
{
	if (player->enemies[i].keycode == 0)
	{
		enemies_animation(player, ((player->enemies[i].enemy_x
					* player->img_width) + (counter * 2)),
			(player->enemies[i].enemy_y * player->img_height), i);
	}
	else if (player->enemies[i].keycode == 2)
	{
		enemies_animation(player,
			((player->enemies[i].enemy_x * player->img_width)
				- (counter * 2)), (player->enemies[i].enemy_y
				* player->img_height), i);
	}
	else if (player->enemies[i].keycode == 1)
	{
		enemies_animation(player, (player->enemies[i].enemy_x
				* player->img_width), ((player->enemies[i].enemy_y
					* player->img_height) + (counter * 2)), i);
	}
	else if (player->enemies[i].keycode == 13)
	{
		enemies_animation(player, (player->enemies[i].enemy_x
				* player->img_width), ((player->enemies[i].enemy_y
					* player->img_height) - (counter * 2)), i);
	}
}

void	making_enemies(t_player *player)
{
	static int	i = 0;
	static int	counter = 25;

	if (counter == 25)
	{
		n_enemy_get_animation_images(player, i);
		enemies_movements(player, i);
	}
	enemy_animations_steps(player, i, counter);
	if ((player->enemies[i].keycode == 0 || player->enemies[i].keycode == 1
			|| player->enemies[i].keycode == 2
			|| player->enemies[i].keycode == 13))
		counter--;
	if (counter == 0)
	{
		put_img_to_window(player, player->background_img,
			player->x * player->img_width, player->y * player->img_height);
		put_img_to_window(player, player->player_img,
			player->x * player->img_width, player->y * player->img_height);
		i++;
		counter = 25;
	}
	if (i == player->c_enemies - 1)
		i = 0;
	check_player_die(player);
}
