/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:51:36 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 14:48:26 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

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

void	count_rows(char **line, int *p_rows, int *p_lines)
{
	int	index;

	index = 0;
	while (*(*line + index) && (*p_lines) == 0)
	{
		index++;
		(*p_rows)++;
	}
	(*p_lines)++;
	free(*line);
}
