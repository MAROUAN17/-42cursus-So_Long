SRCS = so_long_main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	   parsing_map.c map_parsing_utils.c check_reachable.c rendering_images.c \
	   find_player_position.c move_player.c reading_map.c render_background_all_map.c \
	   update_player_position.c
OBJS = ${SRCS:.c=.o}
SRCS_BNS = ./bonus/so_long_main_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	   ./bonus/parsing_map_bonus.c ./bonus/map_parsing_utils_bonus.c ./bonus/check_reachable_bonus.c ./bonus/rendering_images_bonus.c \
	   ./bonus/find_position_bonus.c ./bonus/move_player_bonus.c ./bonus/reading_map_bonus.c ./bonus/render_background_all_map_bonus.c \
	   ./bonus/update_player_position_bonus.c ./bonus/enemy_movement.c
OBJS_BNS = ${SRCS_BNS:.c=.o}
FLAGS = -Wall -Werror -Wextra
CC = cc
NEXT_LINE = ./get_next_line/get_next_line.h
LIBFT_LIB = libft/libft.a
PRINTF_LIB = ft_printf/libftprintf.a

all: so_long

${LIBFT_LIB}: 
		cd ./libft && make

${PRINTF_LIB}: 
		cd ./ft_printf && make

%.o: %.c sl_header.h ${NEXT_LINE}
	$(CC) ${FLAGS} -Imlx -c $< -o $@

so_long: ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB}
	${CC} ${FLAGS} ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB} -fsanitize=address -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long

%_bonus.o: %_bonus.c sl_header_bonus.h ${NEXT_LINE}
	$(CC) ${FLAGS} -Imlx -c $< -o $@

bonus: ${OBJS_BNS} ${LIBFT_LIB} ${PRINTF_LIB}
	${CC} ${FLAGS} ${OBJS_BNS} ${LIBFT_LIB} ${PRINTF_LIB} -fsanitize=address -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o ./bonus/so_long_bonus

clean:
	rm -f ${OBJS} ${OBJS_BNS}
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean: clean
	rm -rf so_long ./bonus/so_long_bonus
	cd ./libft && make fclean
	cd ./ft_printf && make fclean
