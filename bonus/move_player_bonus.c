/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:10:30 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:51:06 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	move_player_right(t_player *player)
{
	int	i;

	i = 0;
	player->keycode = 2;
	if (player->map[player->y][player->x + 1] != '1')
	{
		if (player->map[player->y][player->x + 1] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			if (player->map[player->y][player->x + 1] == 'C')
			{
				player->map[player->y][player->x + 1] = '0';
				player->c_collectibles++;
			}
			player->x += 1;
		}
	}
}

void	move_player_left(t_player *player)
{
	int	i;

	i = 0;
	player->keycode = 0;
	if (player->map[player->y][player->x - 1] != '1')
	{
		if (player->map[player->y][player->x - 1] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			if (player->map[player->y][player->x - 1] == 'C')
			{
				player->map[player->y][player->x - 1] = '0';
				player->c_collectibles++;
			}
			player->x -= 1;
		}
	}
}

void	move_player_up(t_player *player)
{
	int	i;

	i = 0;
	player->keycode = 1;
	if (player->map[player->y - 1][player->x] != '1')
	{
		if (player->map[player->y - 1][player->x] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			if (player->map[player->y - 1][player->x] == 'C')
			{
				player->map[player->y - 1][player->x] = '0';
				player->c_collectibles++;
			}
			player->y -= 1;
		}
	}
}

void	move_player_down(t_player *player)
{
	int	i;

	i = 0;
	player->keycode = 13;
	if (player->map[player->y + 1][player->x] != '1')
	{
		if (player->map[player->y + 1][player->x] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			if (player->map[player->y + 1][player->x] == 'C')
			{
				player->map[player->y + 1][player->x] = '0';
				player->c_collectibles++;
			}
			player->y += 1;
		}
	}
}

void	walking_animation(t_player *player)
{
	static int	j;

	if (j < 8)
	{
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win,
			player->background_img, player->x * player->img_width,
			player->y * player->img_height);
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win,
			player->animations[j], player->x * player->img_width,
			player->y * player->img_height);
		j++;
	}
	if (j == 8)
		j = 0;
}
