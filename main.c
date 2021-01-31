#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"

typedef struct s_map
{
    char    *R;
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *sprite;
    char    *F;
    char    *C;
    int     mapheight;
    int     mapwidth;
    char    **worldmap;
}              t_map;

void    map_init(t_map mapos, char *line, int i)
{
    int j;
    int size;

    size = ft_strlen(line) + 1;
    j = 0;
    mapos.worldmap[i] = (char*)malloc(sizeof(char) * size);
    while (line[j])
    {
        mapos.worldmap[i][j] = line[j];
        j++;
    }
    mapos.worldmap[i][j] = '\0';
}

int     main()
{
    t_map   mapos;
    int     fd;
    char    *line;
    
    mapos.mapheight = 0;
    line = NULL;
    fd = open("map1.cub", O_RDONLY);
    while (get_next_line(fd, &line) != 0)
    {
        if (strchr("RNSWEFC", *line))
        {
            if (line[0] == 'R')
            {
                while (*line == 'R' || *line == ' ')
                    line++;
                mapos.R = ft_strdup(line);
            }
            if (line[0] == 'N' && line[1]== 'O')
            {
                while (*line == 'N' || *line == 'O' || *line == ' ')
                    line++;
                mapos.NO = ft_strdup(line);
            }
            if (line[0] == 'S' && line[1] == 'O')
            {
                while (*line == 'S' || *line == 'O' || *line == ' ')
                    line++;
                mapos.SO = ft_strdup(line);
            }
            if (line[0] == 'W' && line[1] == 'E')
            {
                while (*line == 'W' || *line == 'E' || *line == ' ')
                    line++;
                mapos.WE = ft_strdup(line);
            }
            if (line[0] == 'E' && line[1] == 'A')
            {
                while (*line == 'E' || *line == 'A' || *line == ' ')
                    line++;
                mapos.EA = ft_strdup(line);
            }
            if (line[0] == 'S')
            {
                while (*line == 'S' || *line == ' ')
                    line++;
                mapos.sprite = ft_strdup(line);
            }
            if (line[0] == 'F')
            {
                while (*line == 'F' || *line == ' ')
                    line++;
                mapos.F = ft_strdup(line);
            }
            if (line[0] == 'C')
            {
                while (*line == 'C' || *line == ' ')
                    line++;
                mapos.C = ft_strdup(line);
            }
        }
        else
            mapos.mapheight++;
    }
    mapos.mapheight++;
    close(fd);
    
    int i = 0;
    fd = open("map1.cub", O_RDONLY);
    mapos.worldmap = (char**)malloc(sizeof(char*) * mapos.mapheight);
    while (get_next_line(fd, &line) != 0)
    {
        if (!(strchr("RNSWEFC", *line)))
        {
            map_init(mapos, line, i);
            i++;
        }
    }
    map_init(mapos, line, i);
    
    i = 0;
    int j = 0;
    while (i < mapos.mapheight)
    {
        j = 0;
        while (mapos.worldmap[i][j])
        {
            printf("%c", mapos.worldmap[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    //ft_cub(&mapos);
    return (0);
}
