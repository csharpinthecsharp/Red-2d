/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:37 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 01:53:29 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void openWindow(t_data *d, t_textures *t)
{
    if (!d || !t || !d->mlx) {
        ft_printf("Error\nData or mlx invalid.\n");
        close_game(d);
    }

    t->font = mlx_xpm_file_to_image(d->mlx, t->font_path, &d->width, &d->height);
    t->wall = mlx_xpm_file_to_image(d->mlx, t->wall_path, &d->width, &d->height);
    t->player = mlx_xpm_file_to_image(d->mlx, t->player_path, &d->width, &d->height);
    t->f_00 = mlx_xpm_file_to_image(d->mlx, t->f_00_path, &d->width, &d->height);
    t->exit = mlx_xpm_file_to_image(d->mlx, t->exit_path, &d->width, &d->height);


    if (!t->font || !t->wall) {
        ft_printf("Error\nTexture failed.\n");
        close_game(d);
    }

    d->win = mlx_new_window(d->mlx, 1000, 480, "so_long");
    if (!d->win) {
        ft_printf("Error\nWindow failed to create.\n");
        close_game(d);
    }
}
