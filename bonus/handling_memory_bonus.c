/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_memory_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:51:48 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:18:39 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	free_map(char **map, int lines)
{
	int	y;

	y = 0;
	if (map)
	{
		while (y < lines)
		{
			free(map[y]);
			y++;
		}
		free(map);
	}
}

void	destroy_images(t_player *player)
{
	if (player->background_img)
		mlx_destroy_image(player->mlx_ptr, player->background_img);
	if (player->ground_img)
		mlx_destroy_image(player->mlx_ptr, player->ground_img);
	if (player->collectible_img)
		mlx_destroy_image(player->mlx_ptr, player->collectible_img);
	if (player->exit_img)
		mlx_destroy_image(player->mlx_ptr, player->exit_img);
	if (player->player_img)
		mlx_destroy_image(player->mlx_ptr, player->player_img);
}

void	ft_close(t_player *player, int status)
{
	int	i;

	i = 0;
	if (player->map[0])
		free_map(player->map, player->map_height);
	if (player->mlx_win)
		mlx_destroy_window(player->mlx_ptr, player->mlx_win);
	destroy_images(player);
	while (player->animations[i] && i < 8)
	{
		mlx_destroy_image(player->mlx_ptr, player->animations[i]);
		i++;
	}
	i = 0;
	while (player->e_animations[i] && i < 8)
	{
		mlx_destroy_image(player->mlx_ptr, player->e_animations[i]);
		i++;
	}
	exit(status);
}
