#include "sl_header.h"

char **store_in_2d_array(int fd, int *p_lines, int *p_rows)
{
    int     index;
    int     x;
    int     y;
    char    *line;
    char    **map;

    y = 0;
    map = malloc(sizeof(char **) * *p_lines);
    line = get_next_line(fd);
    while (line)
    {
        index = 0;
        x = 0;
        map[y] = malloc(sizeof(char) * *p_rows);
        while (*(line + index))
        {
            map[y][x] = *(line + index);
            x++;
            index++;
        }
        line = get_next_line(fd);
        y++;
    }
    return (map);
}

char  **reading_map(char *path, int *p_x, int *p_y)
{
    char    **map;
    int     fd;
    int     lines;
    int     rows;

    map = NULL;
    lines = 0;
    rows = 0;
    count_lines_rows(&lines, &rows);
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Map not found!!\n");
        exit(1);
    }
    map = store_in_2d_array(fd, &lines, &rows);
    *p_x = rows;
    *p_y = lines;
    return (map);
}
