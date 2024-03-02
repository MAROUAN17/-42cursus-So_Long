/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:30:11 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/02 18:21:03 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header_bonus.h"

int	infinite_function(t_player *player)
{
	check_player_die(player);
	enemy_following_player(player);
	rendering_collectibles(player);
	making_enemies(player);
	return (0);
}

int	events_handler(int keycode, t_player *player)
{
	if (keycode == 53)
		ft_close(player, 0);
	else if (keycode == 2)
		move_player_right(player);
	else if (keycode == 0)
		move_player_left(player);
	else if (keycode == 1)
		move_player_down(player);
	else if (keycode == 13)
		move_player_up(player);
	update_player_position_and_render(player);
	walking_animation(player);
	display_moves(player);
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

void	initialize_player_struct(t_player *player)
{
	initialize_player_struct_variables(player);
	player->keycode = -1;
	player->e_keycode = -1;
	count_lines_rows(player, &player->map_height, &player->map_width);
	player->mlx_win = mlx_new_window(player->mlx_ptr,
			player->map_width * player->img_width, player->map_height
			* player->img_height, "So_Long");
	if (!player->mlx_win)
		exit(1);
	player->map = reading_map(player);
	find_player_position(player, &player->x, &player->y);
	find_enemy_position(player, &player->enemy_x, &player->enemy_y);
	if (!parsing_map(player))
	{
		initialize_images(player);
		initialize_enemies(player);
		rend_assets(player);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid Map!!\n", 2);
		ft_close(player, 1);
	}
}

int	main(int ac, char **av)
{
	t_player	player;

	if (ac >= 2)
	{
		player.mlx_ptr = mlx_init();
		if (!player.mlx_ptr)
			exit(1);
		player.map_path = av[1];
		initialize_player_struct(&player);
		mlx_hook(player.mlx_win, 2, 1L << 0, events_handler, &player);
		mlx_loop_hook(player.mlx_ptr, infinite_function, &player);
		mlx_loop(player.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Need more arguments!!\n", 2);
		exit(1);
	}
	return (0);
}
