#include "sl_header_bonus.h"

int check_reachable_collectibles(v_player *player)
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
	size.x = player->map_width;
	size.y = player->map_height;
	map_test = reading_map(player);
	flood_fill(map_test, size, player_start, &collectibles, 'C');
	if (collectibles == count_a_tile(player, 'C'))
		check = 0;
	else
		check = 1;
    free_map(map_test, player->map_height);
	return (check);
}

int check_reachable_exits(v_player *player)
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
	size.x = player->map_width;
	size.y = player->map_height;
	map_test = reading_map(player);
	flood_fill(map_test, size, player_start, &exits, 'E');
	if (exits == count_a_tile(player, 'E'))
		check = 0;
	else
		check = 1;
    free_map(map_test, player->map_height);
	return (check);
}
