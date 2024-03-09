/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:56:00 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 20:25:28 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int	check_collectible(t_player *player)
{
	int	check;
	int	collectible;

	collectible = count_a_tile(player, 'C');
	if (collectible == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

int	check_exits(t_player *player)
{
	int	check;
	int	exits;

	exits = count_a_tile(player, 'E');
	if (exits != 1)
		check = 1;
	else
		check = 0;
	return (check);
}

int	check_start(t_player *player)
{
	int	check;
	int	starts;

	starts = count_a_tile(player, 'P');
	if (starts != 1)
		check = 1;
	else
		check = 0;
	return (check);
}

int	count_a_tile(t_player *player, char to_count)
{
	int	x;
	int	y;
	int	counter;

	x = 0;
	y = 0;
	counter = 0;
	while (y < player->map_height)
	{
		x = 0;
		while (x < player->map_width)
		{
			if (player->map[y][x] == to_count)
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

void	count_lines_rows(t_player *player, int *p_lines, int *p_rows)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(player->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line || fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map not found!\n", 2);
		ft_close(player, 1);
	}
	while (line)
	{
		count_rows(&line, p_rows, p_lines);
		line = get_next_line(fd);
	}
	close(fd);
}
