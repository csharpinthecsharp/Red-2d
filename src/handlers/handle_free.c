/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:01:10 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 20:40:41 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    free_textures(t_data *d, t_textures *t)
{
    if (!d->mlx)
        return;
    if (t->font)
        mlx_destroy_image(d->mlx, t->font);
    if (t->wall)
        mlx_destroy_image(d->mlx, t->wall);
    if (t->player)
        mlx_destroy_image(d->mlx, t->player);
    if (t->f_00)
        mlx_destroy_image(d->mlx, t->f_00);
    if (t->exit)
        mlx_destroy_image(d->mlx, t->exit);
}

void    free_map(char **map)
{
    int i = 0;

    if (!map)
        return;
    while (map[i])
        free(map[i++]);
    free(map);
}

void    free_coins(t_data *d)
{
    if (d->coins)
        free(d->coins);
}

int close_game(t_data *d)
{
    free_textures(d, &d->t);
    free_map(d->map);
    free_coins(d);

    if (d->win)
        mlx_destroy_window(d->mlx, d->win);
    if (d->mlx)
    {
        mlx_destroy_display(d->mlx);
        free(d->mlx);
    }
    exit(0);
    return (0);
}
