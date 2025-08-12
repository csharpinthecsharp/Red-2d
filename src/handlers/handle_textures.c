#include "../../include/so_long.h"

int is_right_path(t_textures *t)
{   
    if (!t)
    {
        ft_printf("\x1b[31m * \xE2\x9C\x96 't_textures' is not set correcly!\n");
        return (1);
    }

    if (access(t->font_path, R_OK) != 0)
    {
        ft_printf("\x1b[31m * \xE2\x9C\x96 Assets: %s not accessible!\n", t->font_path);
        return (1);
    }
    else
        ft_printf("\x1b[32m * \xE2\x9C\x94 Assets: %s successfuly loaded!\n", t->font_path);

    if (access(t->wall_path, R_OK) != 0)
    {
        ft_printf("\x1b[31m * \xE2\x9C\x96 Assets: %s not accessible!\n", t->wall_path);
        return (1);
    }
    else
        ft_printf("\x1b[32m * \xE2\x9C\x94 Assets: %s successfuly loaded!\n", t->wall_path);
    return (0);
}

void load_t_path(t_textures *t)
{
    t->font_path = "./src/textures/font.xpm";
    t->wall_path = "./src/textures/wall.xpm";
}

int load_t()
{
    t_textures t;

    load_t_path(&t);
    if (is_right_path(&t))
        return (0);
    return (1);
}