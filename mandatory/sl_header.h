/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maglagal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:14:16 by maglagal          #+#    #+#             */
/*   Updated: 2024/03/08 21:32:33 by maglagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_HEADER_H
# define SL_HEADER_H

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
	void	*background;
	void	*ground;
	void	*collectible;
	void	*exit;
	void	*player;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*map_path;
	char	**map;
	char	**map_test;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		map_width;
	int		map_height;
	int		keycode;
	int		c_collectibles;
	int		moves;
	int		total_collectibles;
	void	*animations[8];
}				t_player;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);
char	**reading_map(t_player *player, char *path);
void	count_lines_rows(t_player *player, int *p_lines, int *p_rows);
int		parsing_map(t_player *player);
int		check_collectible(t_player *player);
int		check_exits(t_player *player);
int		check_start(t_player *player);
int		count_a_tile(t_player *player, char to_count);
int		check_reachable_collectibles(t_player *player);
int		check_reachable_exits(t_player *player);
void	initialize_background(t_player *player);
void	initialize_ground(t_player *player);
void	initialize_collectible(t_player *player);
void	initialize_exit(t_player *player);
void	initialize_player(t_player *player);
void	updating_player_render(t_player *player);
void	find_player_position(t_player *player, int *p_x, int *p_y);
void	move_player_right(t_player *player);
void	move_player_left(t_player *player);
void	move_player_up(t_player *player);
void	move_player_down(t_player *player);
void	walking_animation(t_player *player);
void	rend_assets(t_player *player);
void	get_animation_images(t_player *player);
void	free_map(char **map, int lines);
void	ft_close(t_player *player, int status);
void	initialising_images(t_player *player);
void	initialize_player_struct(t_player *player);
void	rendering_images(t_player *player, int x, int y);
void	put_img_to_window(t_player *player, void *img, int x, int y);
int		path_check(t_player *player);
void	count_rows(char **line, int *p_rows, int *p_lines);
int		destroy_window(t_player *player);

#endif