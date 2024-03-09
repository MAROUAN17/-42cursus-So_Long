/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:22 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/07 20:22:42 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	move_player_right(t_player *player)
{
	if (player->map[player->y][player->x + 1] != '1')
	{
		player->keycode = 2;
		if (player->map[player->y][player->x + 1] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			ft_printf("moves -> %d\n", player->moves);
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
	if (player->map[player->y][player->x - 1] != '1')
	{
		player->keycode = 0;
		if (player->map[player->y][player->x - 1] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			ft_printf("moves -> %d\n", player->moves);
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
	if (player->map[player->y + 1][player->x] != '1')
	{
		player->keycode = 1;
		if (player->map[player->y + 1][player->x] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			ft_printf("moves -> %d\n", player->moves);
			if (player->map[player->y + 1][player->x] == 'C')
			{
				player->map[player->y + 1][player->x] = '0';
				player->c_collectibles++;
			}
			player->y += 1;
		}
	}
}

void	move_player_down(t_player *player)
{
	if (player->map[player->y - 1][player->x] != '1')
	{
		player->keycode = 13;
		if (player->map[player->y - 1][player->x] == 'E')
		{
			if (player->c_collectibles == player->total_collectibles)
				ft_close(player, 0);
		}
		else
		{
			player->moves++;
			ft_printf("moves -> %d\n", player->moves);
			if (player->map[player->y - 1][player->x] == 'C')
			{
				player->map[player->y - 1][player->x] = '0';
				player->c_collectibles++;
			}
			player->y -= 1;
		}
	}
}

void	walking_animation(t_player *player)
{
	static int	j;
	static int	i;

	if (j < 8)
	{
		put_img_to_window(player, player->background,
			player->x * player->img_width, player->y * player->img_height);
		put_img_to_window(player, player->animations[j], player->x
			* player->img_width, player->y * player->img_height);
		j++;
		while (i < 5000000)
			i++;
		i = 0;
	}
	if (j == 8)
		j = 0;
}
