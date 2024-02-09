#include "sl_header.h"

int check_reachable_collectibles(char *path, char **map, int width, int height)
{
	t_point size;
	t_point player_start;
	int		check;
	int		collectibles;
	char	**map_test;

	collectibles = 0;
	check = 0;
	player_start.x = 3;
	player_start.y = 2;
	size.x = width;
	size.y = height;
	map_test = reading_map(path, &width, &height);
	flood_fill(map_test, size, player_start, &collectibles, 'C');
	if (collectibles == count_a_tile(map, width, height, 'C'))
		check = 0;
	else
		check = 1;
    free(map_test);
    map_test = NULL;
	return (check);
}

int check_reachable_exits(char *path, char **map, int width, int height)
{
    t_point size;
	t_point player_start;
	int		check;
	int		exits;
	char	**map_test;

    exits = 0;
	check = 0;
	player_start.x = 3;
	player_start.y = 2;
	size.x = width;
	size.y = height;
	map_test = reading_map(path, &width, &height);
	flood_fill(map_test, size, player_start, &exits, 'E');
	if (exits == count_a_tile(map, width, height, 'E'))
		check = 0;
	else
		check = 1;
    free(map_test);
    map_test = NULL;
	return (check);
}
