#include "sl_header_bonus.h"

char **store_in_2d_array(int fd, v_player *player)
{
    int     y;
    char    *line;
    char    **map;

    y = 0;
    map = malloc(sizeof(char *) * player->map_height);
    if (!map)
        exit(1);
    while (y < player->map_height)
    {
        if (!(line = get_next_line(fd)))
        {
            ft_close(player);
            exit(1);
        }
        if (!(map[y] = ft_strdup(line)))
        {
            ft_close(player);
            exit(1);
        }
        free(line);
        y++;
    }
    return (map);
}

char  **reading_map(v_player *player)
{
    char    **map;
    int     fd;
    int     lines;
    int     rows;

    map = NULL;
    lines = 0;
    rows = 0;
    fd = open(player->map_path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Map not found!!\n");
        ft_close(player);
        exit(1);
    }
    map = store_in_2d_array(fd, player);
    return (map);
}
