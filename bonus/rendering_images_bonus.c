/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_images_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:23:32 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 17:05:17 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	initialize_background(t_player *player)
{
	char	*path;

	path = "../textures/m_Yellow.xpm";
	player->background_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
	if (!player->background_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Path not Found for background image\n", 2);
		ft_close(player, 1);
	}
}

void	initialize_ground(t_player *player)
{
	char	*path;

	path = "../textures/wall.xpm";
	player->ground_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
	if (!player->ground_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Path not Found for ground image\n", 2);
		ft_close(player, 1);
	}
}

void	initialize_collectible(t_player *player)
{
	char	*path;

	path = "../textures/Coin_01.xpm";
	player->collectible_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
	if (!player->collectible_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Path not Found for collectible image\n", 2);
		ft_close(player, 1);
	}
}

void	initialize_exit(t_player *player)
{
	char	*path;

	path = "../textures/Decor_Ruins_02.xpm";
	player->exit_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
	if (!player->exit_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Path not Found for exit image\n", 2);
		ft_close(player, 1);
	}
}

void	initialize_player(t_player *player)
{
	char	*path;

	path = "../textures/walk/Walk 1.xpm";
	player->player_img = mlx_xpm_file_to_image(player->mlx_ptr,
			path, &player->img_width, &player->img_height);
	if (!player->player_img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Path not Found for player image\n", 2);
		ft_close(player, 1);
	}
}
