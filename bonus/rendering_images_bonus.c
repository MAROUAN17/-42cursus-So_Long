/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_images_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:23:32 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 13:28:55 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	initialize_background(t_player *player)
{
	char	*path;

	path = "../assets/m_Yellow.xpm";
	player->background_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
}

void	initialize_ground(t_player *player)
{
	char	*path;

	path = "../assets/wall.xpm";
	player->ground_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
}

void	initialize_collectible(t_player *player)
{
	char	*path;

	path = "../assets/Coin_01.xpm";
	player->collectible_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
}

void	initialize_exit(t_player *player)
{
	char	*path;

	path = "../assets/Decor_Ruins_02.xpm";
	player->exit_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
}

void	initialize_player(t_player *player)
{
	char	*path;

	path = "../assets/walk/Walk 1.xpm";
	player->player_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
}
