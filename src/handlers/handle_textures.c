/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:39 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/16 22:41:08 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int is_right_path(t_textures *t)
{   
    int     i;
    char    *paths[4];

    if (!t)
    {
        ft_printf("%s * %s 't_textures' is not set correctly!\n", RED, NO);
        return (0);
    }
    
    paths[0] = t->font_path;
    paths[1] = t->wall_path;
    paths[2] = t->player_path;
    paths[3] = t->f_00_path;
     
    i = 0;
    while (i <= 3)
    {
        if (access(paths[i], R_OK) != 0)
        {
            ft_printf("%s * %s Assets: %s not accessible!\n", paths[i], RED, NO);
            return (0); 
        }
        else
            ft_printf("%s * %s Assets: %s successfuly loaded!\n", paths[i], GREEN, YES);
        i += 1;
    }
    return (1);
}

void load_t_path(t_textures *t)
{
    t->font_path = "./src/textures/font.xpm";
    t->wall_path = "./src/textures/wall.xpm";
    t->player_path = "./src/textures/player.xpm";

    t->f_00_path = "./src/textures/animation/f_00.xpm";
}

void load_t(t_data *d)
{
    load_t_path(&d->t);
    if (is_right_path(&d->t))
    {
        d->mlx = mlx_init();
        if (!d->mlx) 
        {
            ft_printf("%s * %s MLX: failed to initialise!\n", RED, NO);
            return;
        }
    }
}