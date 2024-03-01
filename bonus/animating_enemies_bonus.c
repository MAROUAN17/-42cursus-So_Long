#include "sl_header_bonus.h"

void n_enemy_get_animation_images(v_player *player, int i)
{
	player->enemies[i].animations[0]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 1.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[1]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 2.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[2]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 3.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[3]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 4.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[4]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 5.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[5]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 6.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[6]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 7.xpm", &player->img_width, &player->img_height);
	player->enemies[i].animations[7]
		= mlx_xpm_file_to_image(player->enemies[i].mlx_ptr,
		"../assets/enemy/enemy 8.xpm", &player->img_width, &player->img_height);
}

void enemies_animation(v_player *player, int x, int y, int i)
{
	static int  j;

	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img,
		player->enemies[i].enemy_x * 50, player->enemies[i].enemy_y * 50);
	if (player->enemies[i].keycode == 2)
	{
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img,
			(player->enemies[i].enemy_x - 1) * 50, player->enemies[i].enemy_y * 50);
	}
	else if (player->enemies[i].keycode == 0)
	{
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img,
			(player->enemies[i].enemy_x + 1) * 50, player->enemies[i].enemy_y * 50);
	}
	else if (player->enemies[i].keycode == 1)
	{
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img,
			player->enemies[i].enemy_x * 50, (player->enemies[i].enemy_y + 1) * 50);
	}
	else if (player->enemies[i].keycode == 13)
	{
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img,
			player->enemies[i].enemy_x * 50, (player->enemies[i].enemy_y - 1) * 50);
	}
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->enemies[i].animations[j], x, y);
	j++;
	if (j == 8)
		j = 0;
}

void	enemies_movements(v_player *player, int i)
{
	static int	direction;

	direction = rand() % 4;
	if (direction == 0 || direction == 2)
		up_down_enemies_movement(player, direction, i);
	else if (direction == 1 || direction == 3)
		right_left_enemies_movement(player, direction, i);
}

void	enemy_animations_steps(v_player *player, int i, int counter)
{
	if (player->enemies[i].keycode == 0)
	{
		enemies_animation(player, ((player->enemies[i].enemy_x * 50)
				+ (counter * 2)), (player->enemies[i].enemy_y * 50), i);
	}
	else if (player->enemies[i].keycode == 2)
	{
		enemies_animation(player, ((player->enemies[i].enemy_x * 50)
				- (counter * 2)), (player->enemies[i].enemy_y * 50), i);
	}
	else if (player->enemies[i].keycode == 1)
	{
		enemies_animation(player, (player->enemies[i].enemy_x * 50),
			((player->enemies[i].enemy_y * 50) + (counter * 2)), i);
	}
	else if (player->enemies[i].keycode == 13)
	{
		enemies_animation(player, (player->enemies[i].enemy_x * 50),
			((player->enemies[i].enemy_y * 50) - (counter * 2)), i);
	}
}

void	making_enemies(v_player *player)
{
	static int	i = 0;
	static int	counter = 25;

	if (i < player->c_enemies - 1)
	{
		if (counter == 25)
		{
			n_enemy_get_animation_images(player, i);
			enemies_movements(player, i);
		}
		enemy_animations_steps(player, i, counter);
		counter--;
		if (counter == 0)
		{
			i++;
			counter = 25;
		}
	}
	if (i == player->c_enemies - 1)
		i = 0;
}
