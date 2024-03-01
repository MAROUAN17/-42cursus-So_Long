SRCS =	./mandatory/so_long_main.c ./mandatory/parsing_map.c ./mandatory/map_parsing_utils.c ./mandatory/check_reachable.c \
		./mandatory/rendering_images.c ./mandatory/find_player_position.c ./mandatory/move_player.c \
		./mandatory/reading_map.c ./mandatory/initializing_all_images.c ./mandatory/update_player_position.c \
		./mandatory/handling_memory.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
SRCS_BNS = ./bonus/so_long_main_bonus.c ./bonus/parsing_map_bonus.c ./bonus/map_parsing_utils_bonus.c ./bonus/check_reachable_bonus.c \
		./bonus/rendering_images_bonus.c ./bonus/find_position_bonus.c ./bonus/move_player_bonus.c ./bonus/reading_map_bonus.c \
		./bonus/render_element_all_map_bonus.c ./bonus/update_player_position_bonus.c ./bonus/enemy_movement_bonus.c ./bonus/moves_display_screen_bonus.c \
		./bonus/animating_enemies_bonus.c ./bonus/initialization_bonus.c ./bonus/handling_memory_bonus.c \
		./bonus/choosing_movement_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS_BNS = ${SRCS_BNS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc
NEXT_LINE_H = ./get_next_line/get_next_line.h
LIBFT_LIB = ./libft/libft.a
PRINTF_LIB = ./ft_printf/libftprintf.a

all: so_long

${LIBFT_LIB}: 
		cd ./libft && make

${PRINTF_LIB}: 
		cd ./ft_printf && make

%.o: %.c ./mandatory/sl_header.h ${NEXT_LINE_H}
	$(CC) ${CFLAGS} -c $< -o $@

so_long: ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${PRINTF_LIB} -lmlx -framework OpenGL -framework AppKit -o ./mandatory/so_long

%_bonus.o: %_bonus.c ./bonus/sl_header_bonus.h ${NEXT_LINE}
	$(CC) ${CFLAGS} -c $< -o $@

bonus: ${OBJS_BNS} ${LIBFT_LIB} ${PRINTF_LIB}
	${CC} ${CFLAGS} ${OBJS_BNS} ${LIBFT_LIB} ${PRINTF_LIB} -lmlx -framework OpenGL -framework AppKit -o ./bonus/so_long_bonus

re:
	make fclean
	make all

clean:
	rm -f ${OBJS} ${OBJS_BNS} ${NEXT_LINE_OBJS}
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean: clean
	rm -rf ./mandatory/so_long ./bonus/so_long_bonus
	cd ./libft && make fclean
	cd ./ft_printf && make fclean
