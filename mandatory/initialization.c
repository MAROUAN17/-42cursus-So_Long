/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:52:21 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 15:00:30 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	put_img_to_window(t_player *player, void *img, int x, int y)
{
	if (!img)
		ft_close(player, 1);
	else
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img, x, y);
}

void	initialize_player_struct(t_player *player)
{
	int	i;

	i = 0;
	player->mlx_win = NULL;
	player->background = NULL;
	player->ground = NULL;
	player->collectible = NULL;
	player->exit = NULL;
	player->player = NULL;
	player->map_height = 0;
	player->map_width = 0;
	player->c_collectibles = 0;
	player->moves = 0;
	player->x = 0;
	player->y = 0;
	player->img_height = 50;
	player->img_width = 50;
	while (i < 8)
	{
		player->animations[i] = NULL;
		i++;
	}
}

void	initialising_images(t_player *player)
{
	initialize_background(player);
	initialize_ground(player);
	initialize_collectible(player);
	initialize_exit(player);
	initialize_player(player);
	get_animation_images(player);
}

void	rendering_images(t_player *player, int x, int y)
{
	put_img_to_window(player, player->background,
		x * player->img_width, y * player->img_height);
	if (player->map[y][x] == '1')
		put_img_to_window(player, player->ground,
			x * player->img_width, y * player->img_height);
	else if (player->map[y][x] == 'C')
		put_img_to_window(player, player->collectible,
			x * player->img_width, y * player->img_height);
	else if (player->map[y][x] == 'E')
		put_img_to_window(player, player->exit,
			x * player->img_width, y * player->img_height);
	else if (player->map[y][x] == 'P')
		put_img_to_window(player, player->player,
			x * player->img_width, y * player->img_height);
}

void	get_animation_images(t_player *player)
{
	player->animations[0] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 1.xpm", &player->img_width,
			&player->img_height);
	player->animations[1] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 2.xpm", &player->img_width,
			&player->img_height);
	player->animations[2] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 3.xpm", &player->img_width,
			&player->img_height);
	player->animations[3] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 4.xpm", &player->img_width,
			&player->img_height);
	player->animations[4] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 5.xpm", &player->img_width,
			&player->img_height);
	player->animations[5] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 6.xpm", &player->img_width,
			&player->img_height);
	player->animations[6] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 7.xpm", &player->img_width,
			&player->img_height);
	player->animations[7] = mlx_xpm_file_to_image(player->mlx_ptr,
			"../textures/walk/Walk 8.xpm", &player->img_width,
			&player->img_height);
}
