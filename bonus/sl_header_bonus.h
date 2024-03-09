/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:39:04 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/06 16:35:35 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_HEADER_BONUS_H
# define SL_HEADER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_player
{
	void			*background_img;
	void			*ground_img;
	void			*collectible_img;
	void			*exit_img;
	void			*player_img;
	void			*enemy_img;
	void			*mlx_ptr;
	void			*mlx_win;
	char			to_check_fl;
	char			**map;
	char			*map_path;
	char			**map_test;
	int				img_width;
	int				img_height;
	int				x;
	int				y;
	int				enemy_x;
	int				enemy_y;
	int				map_width;
	int				map_height;
	int				keycode;
	int				e_keycode;
	int				c_collectibles;
	int				moves;
	int				total_collectibles;
	int				c_enemies;
	struct s_player	*enemies;
	void			*animations[8];
	void			*e_animations[6];
}					t_player;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);
char	**reading_map(t_player *player);
void	count_lines_rows(t_player *player, int *p_lines, int *p_rows);
int		parsing_map(t_player *player);
int		path_check(t_player *player);
int		check_collectible(t_player *player);
int		check_exits(t_player *player);
int		check_start(t_player *player);
int		count_a_tile(t_player *player, char to_count);
int		check_reachable_collectibles(t_player *player);
int		check_reachable_exits(t_player *player);
void	initialize_images(t_player *player);
void	initialize_background(t_player *player);
void	initialize_ground(t_player *player);
void	initialize_collectible(t_player *player);
void	initialize_exit(t_player *player);
void	initialize_player(t_player *player);
void	initialize_enemy(t_player *player);
void	update_player_position_and_render(t_player *player);
void	find_player_position(t_player *player, int *p_x, int *p_y);
void	move_player_right(t_player *player);
void	move_player_left(t_player *player);
void	move_player_up(t_player *player);
void	move_player_down(t_player *player);
void	walking_animation(t_player *player);
void	rend_assets(t_player *player);
void	get_animation_images(t_player *player);
void	enemy_get_animation_images(t_player *enemy);
void	find_enemy_position(t_player *player, int *p_x, int *p_y);
void	enemy_animation(t_player *enemy, int x, int y);
void	enemy_following_player(t_player *enemy);
void	display_moves(t_player *player);
void	rendering_collectibles(t_player *player);
void	making_enemies(t_player *player);
void	initialize_enemies(t_player *player);
int		count_enemies(t_player *player);
void	initialize_images(t_player *player);
void	free_map(char **map, int lines);
void	ft_close(t_player *player, int status);
void	initialize_player_struct_variables(t_player *player);
void	check_player_die(t_player *player);
void	up_down_movement(t_player *player, int up_down);
void	right_left_movement(t_player *player, int right_left);
void	up_down_enemies_movement(t_player *player, int direction, int i);
void	right_left_enemies_movement(t_player *player, int direction, int i);
void	put_img_to_window(t_player *player, void *img, int x, int y);
void	destroy_images(t_player *player);
void	rendering_images(t_player *player, int x, int y);
void	initialize_all_animations(t_player *player);
void	count_rows(char **line, int *p_rows, int *p_lines);
int		destroy_window(t_player *player);

#endif