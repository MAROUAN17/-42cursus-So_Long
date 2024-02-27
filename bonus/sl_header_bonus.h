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

# ifndef HEADER_H
#define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_point {
	int		x;
	int		y;
}				t_point;

typedef struct s_player {
	void			*mlx_ptr;
	void			*mlx_win;
	char			**map;
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
}				v_player;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);
char	**reading_map(char *path, int *p_x, int *p_y);
void	count_lines_rows(char *path, int *p_lines, int *p_rows);
int		parsing_map(char *path, char **map, int width, int height);
int		check_collectible(char **map, int width, int height);
int		check_exits(char **map, int width, int height);
int		check_start(char **map, int width, int height);
int		count_a_tile(char **map, int width, int height, char to_count);
void	flood_fill(char **map, t_point size, t_point cur,int *p_counter, char to_check);
int		check_reachable_collectibles(char *path, char **map, int width, int height);
int		check_reachable_exits(char *path, char **map, int width, int height);
void	rendering_background(void *mlx_ptr, void *mlx_win, int x, int y);
void	rendering_ground(v_player *player, int x, int y);
void	rendering_collectible(void *mlx_ptr, void *mlx_win, int x, int y);
void	rendering_exit(v_player *player, int x, int y);
void	rendering_player(v_player *player, int x, int y);
void	rendering_player_rev(v_player *player, int x, int y);
void	update_player_position_and_render(v_player *player);
void	find_player_position(v_player *player, int *p_x, int *p_y);
void	move_player_right(v_player *player);
void	move_player_left(v_player *player);
void	move_player_up(v_player *player);
void	move_player_down(v_player *player);
void	walking_animation(v_player *player);
void	render_map_image_all_map(v_player *player, int x, int y);
void	rend_assets(v_player *player, char **map, int width, int height);
void	get_animation_images(v_player *player);
void	rendering_enemy(v_player *player, int x, int y);
void	enemy_get_animation_images(v_player *enemy);
void	find_enemy_position(v_player *player, int *p_x, int *p_y, int is_main);
void	enemy_animation(v_player *enemy, int x, int y);
void	enemy_following_player(v_player *enemy);
void	display_moves(v_player *player);
void	rendering_collectibles(v_player *enemy, char **map, int width, int height);
void	initialize_enemies(v_player *player);
int		count_enemies(char **map, int width, int height);
void	making_enemies(v_player *player);

#endif
