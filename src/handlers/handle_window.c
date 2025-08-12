/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:37 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/12 16:12:14 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void openWindow(t_data *d, t_textures *t)
{
    if (!d || !t || !d->mlx) {
        ft_printf("%s * %s Invalid data or MLX instance!\n", RED, NO);
        return;
    }

    t->font = mlx_xpm_file_to_image(d->mlx, t->font_path, &d->width, &d->height);
    t->wall = mlx_xpm_file_to_image(d->mlx, t->wall_path, &d->width, &d->height);

    if (!t->font || !t->wall) {
        ft_printf("%s * %s MLX: could not load XPM file!\n", RED, NO);
        if (t->font) mlx_destroy_image(d->mlx, t->font);
        if (t->wall) mlx_destroy_image(d->mlx, t->wall);
        return;
    }

    d->win = mlx_new_window(d->mlx, 800, 400, "My Minecraft 2D Game :)");
    if (!d->win) {
        ft_printf("%s * %s Window: Creation failed!\n", RED, NO);
        mlx_destroy_image(d->mlx, t->font);
        mlx_destroy_image(d->mlx, t->wall);
        return;
    }

    ft_printf("%s * %s Window: Successfuly created!\n", GREEN, YES);

    mlx_hook(d->win, 2, 1L << 0, exitKey, d);
    mlx_loop(d->mlx);
}
