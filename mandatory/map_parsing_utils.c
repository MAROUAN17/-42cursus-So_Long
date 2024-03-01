#include "sl_header.h"

int check_collectible(char **map, int width, int height)
{
	int x;
	int y;
	int check;
	int collectible;

	x = 0;
	y = 0;
	check = 0;
	collectible = 0;
	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			if (map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	if(collectible == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

int check_exits(char **map, int width, int height)
{
	int x;
	int y;
	int check;
	int exits;

	x = 0;
	y = 0;
	check = 0;
	exits = 0;
	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			if(map[y][x] == 'E')
				exits++;
			x++;
		}
		y++;
	}
	if(exits == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

int check_start(char **map, int width, int height)
{
	int x;
	int y;
	int check;
	int starts;

	x = 0;
	y = 0;
	check = 0;
	starts = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
				starts++;
			x++;
		}
		y++;
	}
	if (starts == 0)
		check = 1;
	else
		check = 0;
	return (check);
}

int count_a_tile(v_player *player, char to_count)
{
	int	x;
	int	y;
	int	counter;

	x = 0;
	y = 0;
	counter = 0;
	while (y < player->map_height)
	{
		x = 0;
		while (x < player->map_width)
		{
			if (player->map[y][x] == to_count)
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

void flood_fill(char **map, t_point size, t_point cur,int *p_counter, char to_check)
{
	if (cur.y >= size.y || cur.x >= size.x || cur.x < 0
		|| cur.y < 0 || map[cur.y][cur.x] == '1')
		return;
	if (map[cur.y][cur.x] == to_check)
		(*p_counter)++;
	map[cur.y][cur.x] = '1';
	flood_fill(map, size, (t_point){cur.x - 1, cur.y}, p_counter, to_check);
	flood_fill(map, size, (t_point){cur.x + 1, cur.y}, p_counter, to_check);
	flood_fill(map, size, (t_point){cur.x, cur.y + 1}, p_counter, to_check);
	flood_fill(map, size, (t_point){cur.x, cur.y - 1}, p_counter, to_check);
}
