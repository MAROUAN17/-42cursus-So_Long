/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:46:43 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 15:56:14 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	initialize_player_struct_variables(t_player *player)
{
	int	i;

	i = 0;
	player->mlx_win = NULL;
	player->background_img = NULL;
	player->ground_img = NULL;
	player->collectible_img = NULL;
	player->exit_img = NULL;
	player->player_img = NULL;
	while (i < 8)
	{
		player->animations[i] = NULL;
		i++;
	}
	player->enemy_x = 0;
	player->enemy_y = 0;
	player->map_width = 0;
	player->map_height = 0;
	player->c_collectibles = 0;
	player->moves = 0;
	player->x = 0;
	player->y = 0;
	player->img_height = 50;
	player->img_width = 50;
}

void	initialize_enemies(t_player *player)
{
	int			i;
	t_player	enemy;

	i = 0;
	enemy.enemy_x = 0;
	enemy.enemy_y = 0;
	player->c_enemies = count_enemies(player->map,
			player->map_width, player->map_height);
	player->enemies = malloc(sizeof(t_player) * player->c_enemies);
	while (i < player->c_enemies - 1)
	{
		enemy.keycode = -1;
		enemy.e_keycode = -1;
		enemy.mlx_ptr = player->mlx_ptr;
		enemy.mlx_win = player->mlx_win;
		enemy.map = player->map;
		enemy.map_height = player->map_height;
		enemy.map_width = player->map_width;
		enemy.x = player->x;
		enemy.y = player->y;
		find_enemy_position(player, &enemy.enemy_x, &enemy.enemy_y);
		player->enemies[i] = enemy;
		i++;
	}
}

void	initialize_images(t_player *player)
{
	initialize_background(player);
	initialize_ground(player);
	initialize_collectible(player);
	initialize_exit(player);
	initialize_player(player);
	initialize_enemy(player);
	get_animation_images(player);
	enemy_get_animation_images(player);
}

void	initialize_enemy(t_player *player)
{
	char	*path;

	path = "../assets/enemy/enemy 1.xpm";
	player->enemy_img = mlx_xpm_file_to_image(player->mlx_ptr, path,
			&player->img_width, &player->img_height);
}

void	get_animation_images(t_player *player)
{
	player->animations[0] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 1.xpm", &player->img_width,
			&player->img_height);
	player->animations[1] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 2.xpm", &player->img_width,
			&player->img_height);
	player->animations[2] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 3.xpm", &player->img_width,
			&player->img_height);
	player->animations[3] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 4.xpm", &player->img_width,
			&player->img_height);
	player->animations[4] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 5.xpm", &player->img_width,
			&player->img_height);
	player->animations[5] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 6.xpm", &player->img_width,
			&player->img_height);
	player->animations[6] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 7.xpm", &player->img_width,
			&player->img_height);
	player->animations[7] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../assets/walk/Walk 8.xpm", &player->img_width,
			&player->img_height);
}