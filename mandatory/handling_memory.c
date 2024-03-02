/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:51:57 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:17:15 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

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

void	ft_close(t_player *player, int status)
{
	int	i;

	i = 0;
	free_map(player->map, player->map_height);
	if (player->mlx_win)
		mlx_destroy_window(player->mlx_ptr, player->mlx_win);
	if (player->background)
		mlx_destroy_image(player->mlx_ptr, player->background);
	if (player->ground)
		mlx_destroy_image(player->mlx_ptr, player->ground);
	if (player->collectible)
		mlx_destroy_image(player->mlx_ptr, player->collectible);
	if (player->exit)
		mlx_destroy_image(player->mlx_ptr, player->exit);
	if (player->player)
		mlx_destroy_image(player->mlx_ptr, player->player);
	while (player->animations[i] && i < 8)
	{
		mlx_destroy_image(player->mlx_ptr, player->animations[i]);
		i++;
	}
	exit(status);
}
