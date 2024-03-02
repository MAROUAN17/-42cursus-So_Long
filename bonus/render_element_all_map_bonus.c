/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_element_all_map_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:23:00 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:51:49 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	rendering_collectibles(t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < player->map_height)
	{
		x = 0;
		while (x < player->map_width)
		{
			if (player->map[y][x] == 'C')
			{
				mlx_put_image_to_window(player->mlx_ptr,
					player->mlx_win, player->background_img,
					x * player->img_width, y * player->img_height);
				mlx_put_image_to_window(player->mlx_ptr,
					player->mlx_win, player->collectible_img,
					x * player->img_width, y * player->img_height);
			}
			x++;
		}
		y++;
	}
}
