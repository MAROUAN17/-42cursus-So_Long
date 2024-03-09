/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils_bonus2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:53:26 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/06 16:34:59 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

int	path_check(t_player *player)
{
	int		path_len;
	int		extension_len;
	int		check;
	char	*extension;

	extension = ".ber";
	extension_len = ft_strlen(extension);
	path_len = ft_strlen(player->map_path);
	if (!ft_strncmp(player->map_path + path_len - extension_len, extension, 4))
		check = 0;
	else
		check = 1;
	return (check);
}

void	rendering_images(t_player *player, int x, int y)
{
	put_img_to_window(player, player->background_img,
		x * player->img_height, y * player->img_width);
	if (player->map[y][x] == '1')
		put_img_to_window(player, player->ground_img,
			x * player->img_height, y * player->img_width);
	else if (player->map[y][x] == 'C')
		put_img_to_window(player, player->collectible_img,
			x * player->img_height, y * player->img_width);
	else if (player->map[y][x] == 'E')
		put_img_to_window(player, player->exit_img,
			x * player->img_height, y * player->img_width);
	else if (player->map[y][x] == 'P')
		put_img_to_window(player, player->player_img,
			x * player->img_height, y * player->img_width);
	else if (player->map[y][x] == 'M')
		put_img_to_window(player, player->enemy_img,
			x * player->img_height, y * player->img_width);
}
