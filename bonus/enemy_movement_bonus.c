/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:34:51 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/06 16:36:16 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

int	count_enemies(t_player *player)
{
	int	x;
	int	y;
	int	counter;

	x = 0;
	y = 0;
	counter = 0;
	while (y < player->map_height)
	{
		x = 0;
		while (x < player->map_width)
		{
			if (player->map[y][x] == 'M')
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

void	enemy_get_animation_images(t_player *player)
{
	player->e_animations[0] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/enemy/enemy 1.xpm", &player->img_width,
			&player->img_height);
	player->e_animations[1]
		= mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/enemy/enemy 2.xpm",
			&player->img_width, &player->img_height);
	player->e_animations[2]
		= mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/enemy/enemy 3.xpm",
			&player->img_width, &player->img_height);
	player->e_animations[3]
		= mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/enemy/enemy 4.xpm",
			&player->img_width, &player->img_height);
	player->e_animations[4]
		= mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/enemy/enemy 5.xpm",
			&player->img_width, &player->img_height);
	player->e_animations[5]
		= mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/enemy/enemy 6.xpm",
			&player->img_width, &player->img_height);
}

void	enemy_animation(t_player *player, int x, int y)
{
	static int	j;

	put_img_to_window(player, player->background_img,
		player->enemy_x * player->img_width,
		player->enemy_y * player->img_height);
	if (player->e_keycode == 2)
		put_img_to_window(player, player->background_img, (player->enemy_x - 1)
			* player->img_width, player->enemy_y * player->img_height);
	else if (player->e_keycode == 0)
		put_img_to_window(player, player->background_img, (player->enemy_x + 1)
			* player->img_width, player->enemy_y * player->img_height);
	else if (player->e_keycode == 1)
		put_img_to_window(player, player->background_img, player->enemy_x
			* player->img_width, (player->enemy_y + 1) * player->img_height);
	else if (player->e_keycode == 13)
		put_img_to_window(player, player->background_img, player->enemy_x
			* player->img_width, (player->enemy_y - 1) * player->img_height);
	put_img_to_window(player, player->e_animations[j], x, y);
	j++;
	if (j == 6)
		j = 0;
}

void	enemy_step_move(t_player *player)
{
	if (player->x > player->enemy_x
		&& player->map[player->enemy_y][player->enemy_x + 1] != '1'
		&& player->map[player->enemy_y][player->enemy_x + 1] != 'E')
		right_left_movement(player, 1);
	else if (player->x < player->enemy_x
		&& player->map[player->enemy_y][player->enemy_x - 1] != '1'
		&& player->map[player->enemy_y][player->enemy_x - 1] != 'E')
		right_left_movement(player, 0);
	else if (player->y < player->enemy_y
		&& player->map[player->enemy_y - 1][player->enemy_x] != '1'
		&& player->map[player->enemy_y - 1][player->enemy_x] != 'E')
		up_down_movement(player, 1);
	else if (player->y > player->enemy_y
		&& player->map[player->enemy_y + 1][player->enemy_x] != '1'
		&& player->map[player->enemy_y + 1][player->enemy_x] != 'E')
		up_down_movement(player, 0);
}

void	enemy_following_player(t_player *player)
{
	static int	counter = 25;

	if (counter == 25)
		enemy_step_move(player);
	if (player->e_keycode == 0)
		enemy_animation(player, ((player->enemy_x * player->img_width)
				+ (counter * 2)), player->enemy_y * player->img_height);
	else if (player->e_keycode == 2)
		enemy_animation(player, ((player->enemy_x * player->img_width)
				- (counter * 2)), player->enemy_y * player->img_height);
	else if (player->e_keycode == 1)
		enemy_animation(player, player->enemy_x * player->img_width,
			((player->enemy_y * player->img_height) + (counter * 2)));
	else if (player->e_keycode == 13)
		enemy_animation(player, player->enemy_x * player->img_width,
			((player->enemy_y * player->img_height) - (counter * 2)));
	counter--;
	mlx_do_sync(player->mlx_ptr);
	if (counter < 0)
	{
		counter = 25;
		player->e_keycode = -1;
	}
	check_player_die(player);
}
