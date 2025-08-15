/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:37 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/15 04:25:31 by ltrillar         ###   ########.fr       */
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
    t->player = mlx_xpm_file_to_image(d->mlx, t->player_path, &d->width, &d->height);

    if (!t->font || !t->wall) {
        ft_printf("%s * %s MLX: could not load XPM file!\n", RED, NO);
        if (t->font) mlx_destroy_image(d->mlx, t->font);
        if (t->wall) mlx_destroy_image(d->mlx, t->wall);
        if (t->player) mlx_destroy_image(d->mlx, t->player);
        return;
    }

    d->win = mlx_new_window(d->mlx, 1000, 480, "Minecraft si kaaris avait pas mis la lumiere sur sevran");
    if (!d->win) {
        ft_printf("%s * %s Window: Creation failed!\n", RED, NO);
        mlx_destroy_image(d->mlx, t->font);
        mlx_destroy_image(d->mlx, t->wall);
        mlx_destroy_image(d->mlx, t->player);
        return;
    }

    ft_printf("%s * %s Window: Successfuly created!\n", GREEN, YES);
}
