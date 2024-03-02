/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:50:20 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:19:15 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	find_player_position(t_player *player, int *p_x, int *p_y)
{
	while (*p_y < player->map_height)
	{
		*p_x = 0;
		while (*p_x < player->map_width)
		{
			if (player->map[*p_y][*p_x] == 'P')
				return ;
			(*p_x)++;
		}
		(*p_y)++;
	}
}

void	find_enemy_position(t_player *player, int *p_x, int *p_y)
{
	static int	last_x;
	static int	last_y;

	*p_x = last_x;
	*p_y = last_y;
	while (*p_y < player->map_height)
	{
		if (*p_x == player->map_width)
			*p_x = 0;
		while (*p_x < player->map_width)
		{
			if (player->map[*p_y][*p_x] == 'M')
			{
				if (*p_x != last_x || *p_y != last_y)
				{
					last_x = *p_x;
					last_y = *p_y;
					return ;
				}
			}
			(*p_x)++;
		}
		(*p_y)++;
	}
}

void	check_player_die(t_player *player)
{
	static int	i;

	if (player->x == player->enemy_x && player->y == player->enemy_y)
	{
		ft_printf("You Died\n");
		ft_close(player, 0);
	}
	while (i < player->c_enemies - 1)
	{
		if (player->x == player->enemies[i].enemy_x
			&& player->y == player->enemies[i].enemy_y)
		{
			ft_printf("You Died\n");
			ft_close(player, 0);
		}
		i++;
	}
	if (i == player->c_enemies - 1)
		i = 0;
}
