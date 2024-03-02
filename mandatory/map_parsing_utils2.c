/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:34:14 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:34:19 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

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
