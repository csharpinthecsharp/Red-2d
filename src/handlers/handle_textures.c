/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:39 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/12 15:57:19 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int is_right_path(t_textures *t)
{   
    if (!t)
    {
        ft_printf("%s * %s 't_textures' is not set correcly!\n", RED, NO);
        return (0);
    }

    if (access(t->font_path, R_OK) != 0)
    {
        ft_printf("%s * %s Assets: %s not accessible!\n", t->font_path, RED, NO);
        return (0);
    }
    else
        ft_printf("%s * %s Assets: %s successfuly loaded!\n", GREEN, YES, t->font_path);

    if (access(t->wall_path, R_OK) != 0)
    {
        ft_printf("%s * %s Assets: %s not accessible!\n", RED, NO, t->wall_path);
        return (0);
    }
    else
        ft_printf("%s * %s Assets: %s successfuly loaded!\n", GREEN, YES, t->wall_path);
    return (1);
}

void load_t_path(t_textures *t)
{
    t->font_path = "./src/textures/font.xpm";
    t->wall_path = "./src/textures/wall.xpm";
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
        ft_printf("%s * %s MLX: successfuly initialise!\n", GREEN, YES);
    }
}