/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:01:10 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 01:56:41 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void free_textures(t_data *d, t_textures *t)
{
    if (t->font_path)
        mlx_destroy_image(d->mlx, t->font);
    if (t->wall_path)
        mlx_destroy_image(d->mlx, t->wall);
    if (t->player_path)
        mlx_destroy_image(d->mlx, t->player);
    if (t->f_00)
        mlx_destroy_image(d->mlx, t->f_00);
    if (t->exit)
        mlx_destroy_image(d->mlx, t->exit);
}

int close_game(t_data *d)
{
    free_textures(d, &d->t);
    mlx_destroy_window(d->mlx, d->win);
    mlx_destroy_display(d->mlx);
    free(d->mlx);
    exit(0);
    return (0);
}