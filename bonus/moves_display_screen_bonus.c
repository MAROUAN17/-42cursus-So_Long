/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_display_screen_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:15:21 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:31 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

void	display_moves(t_player *player)
{
	char	*moves;

	moves = ft_itoa(player->moves);
	if (!moves)
		ft_close(player, 1);
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win,
		player->ground_img, 0, 0);
	mlx_string_put(player->mlx_ptr, player->mlx_win, 0, 0, 0xFFFFFF, moves);
	free(moves);
}
