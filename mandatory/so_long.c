/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:44:37 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/04 19:41:50 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int	events_handler(int keycode, t_player *player)
{
	if (keycode == 53 || keycode == 2 || keycode == 1
		|| keycode == 13 || keycode == 0 || keycode == 17)
	{
		if (keycode == 53 || keycode == 17)
			ft_close(player, 0);
		else if (keycode == 2)
			move_player_right(player);
		else if (keycode == 0)
			move_player_left(player);
		else if (keycode == 1)
			move_player_up(player);
		else if (keycode == 13)
			move_player_down(player);
		updating_player_render(player);
		walking_animation(player);
	}
	return (0);
}

void	rend_assets(t_player *player)
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
			rendering_images(player, x, y);
			x++;
		}
		y++;
	}
}

void	intialise_player(t_player *player, char *path)
{
	initialize_player_struct(player);
	count_lines_rows(player, &player->map_height, &player->map_width);
	player->mlx_win = mlx_new_window(player->mlx_ptr,
			player->map_width * player->img_width,
			player->map_height * player->img_height, "So_Long");
	if (!player->mlx_win)
		ft_close(player, 1);
	player->map = reading_map(player, path);
	player->total_collectibles = count_a_tile(player, 'C');
	find_player_position(player, &player->x, &player->y);
	if (!parsing_map(player))
	{
		initialising_images(player);
		rend_assets(player);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Non Valid Map!!\n", 2);
		ft_close(player, 1);
	}
}

int	main(int ac, char **av)
{
	t_player	player;

	if (ac == 2)
	{
		player.mlx_ptr = mlx_init();
		if (!player.mlx_ptr)
			exit(1);
		player.map = NULL;
		player.map_path = av[1];
		intialise_player(&player, player.map_path);
		mlx_hook(player.mlx_win, 2, 1L << 0, events_handler, &player);
		mlx_hook(player.mlx_win, 17, 1L << 0, destroy_window, &player);
		mlx_loop(player.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Parameteres Error!!\n", 2);
		exit(1);
	}
	return (0);
}
