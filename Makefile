SRCS = so_long_main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	   parsing_map.c map_parsing_utils.c check_reachable.c rendering_images.c \
	   find_player_position.c move_player.c reading_map.c render_background_all_map.c \
	   update_player_position.c
OBJS = ${SRCS:.c=.o}
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

clean:
	rm -f ${OBJS}
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean: clean
	rm -rf so_long
	cd ./libft && make fclean
	cd ./ft_printf && make fclean
