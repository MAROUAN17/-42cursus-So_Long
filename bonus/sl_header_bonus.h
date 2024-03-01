/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <maglagal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:39:04 by maglagal          #+#    #+#             */
/*   Updated: 2024/02/08 15:11:17 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SL_HEADER_BONUS_H
#define SL_HEADER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_point {
	int		x;
	int		y;
}				t_point;

typedef struct s_player {
	void			*background_img;
	void			*ground_img;
	void			*collectible_img;
	void			*exit_img;
	void			*player_img;
	void			*enemy_img;
	void			*mlx_ptr;
	void			*mlx_win;
	char			**map;
	char			*map_path;
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
	void			*e_animations[8];
}				v_player;

char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);
char	**reading_map(v_player *player);
void	count_lines_rows(v_player *player, int *p_lines, int *p_rows);
int		parsing_map(v_player *player);
int		check_collectible(char **map, int width, int height);
int		check_exits(char **map, int width, int height);
int		check_start(char **map, int width, int height);
int		count_a_tile(v_player *player, char to_count);
void	flood_fill(char **map, t_point size, t_point cur,int *p_counter, char to_check);
int		check_reachable_collectibles(v_player *player);
int		check_reachable_exits(v_player *player);
void	initialize_images(v_player *player);
void	initialize_background(v_player *player);
void	initialize_ground(v_player *player);
void	initialize_collectible(v_player *player);
void	initialize_exit(v_player *player);
void	initialize_player(v_player *player);
void	initialize_enemy(v_player *player);
void	update_player_position_and_render(v_player *player);
void	find_player_position(v_player *player, int *p_x, int *p_y);
void	move_player_right(v_player *player);
void	move_player_left(v_player *player);
void	move_player_up(v_player *player);
void	move_player_down(v_player *player);
void	walking_animation(v_player *player);
void	rend_assets(v_player *player);
void	get_animation_images(v_player *player);
void	enemy_get_animation_images(v_player *enemy);
void	find_enemy_position(v_player *player, int *p_x, int *p_y);
void	enemy_animation(v_player *enemy, int x, int y);
void	enemy_following_player(v_player *enemy);
void	display_moves(v_player *player);
void	rendering_collectibles(v_player *player);
void	making_enemies(v_player *player);
void	initialize_enemies(v_player *player);
int		count_enemies(char **map, int width, int height);
void	initialize_images(v_player *player);
void	free_map(char **map, int lines);
void	ft_close(v_player *player);
void    initialize_player_struct_variables(v_player *player);
void	check_player_die(v_player *player);
void	up_down_movement(v_player *player, int up_down);
void	right_left_movement(v_player *player, int right_left);
void	up_down_enemies_movement(v_player *player, int direction, int i);
void	right_left_enemies_movement(v_player *player, int direction, int i);
void	put_img_to_window(v_player *player, void *img, int x, int y);

# endif
