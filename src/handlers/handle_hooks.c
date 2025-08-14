/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:47:22 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/15 01:35:42 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int exitKey(int keycode, t_data *d)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(d->mlx, d->win);
        ft_printf("%s%s Closing... \n", RED, CRY);
        exit(0);
    }
    return (0);
}

int keyPress(int keycode, t_data *d)
{
    t_textures *t = &d->t;
    static int count;

    if (!d || !d->mlx || !d->win || !t->font || !t->player) {
        ft_printf("%s * %s Invalid data or textures!\n", RED, NO);
        return (0);
    }

    if (keycode == 65307)
    {
        mlx_destroy_window(d->mlx, d->win);
        ft_printf("%s%s Closing... \n", RED, CRY);
        close_game(d); 
        return (0);
    }

    mlx_put_image_to_window(d->mlx, d->win, t->font, d->player_x * TILE_SIZE, d->player_y * TILE_SIZE);

    count++;
    if (keycode == 65361 || keycode == 'q') { 
        d->player_x -= 1;
        ft_printf("%d %s * %s Left pressed!\n", count, GREEN, YES);
    }
    else if (keycode == 65362 || keycode == 'z') { 
        d->player_y -= 1;
        ft_printf("%d %s * %s Up pressed!\n", count, GREEN, YES);
    }
    else if (keycode == 65363 || keycode == 'd') { 
        d->player_x += 1;
        ft_printf("%d %s * %s Right pressed!\n", count, GREEN, YES);
    }
    else if (keycode == 65364 || keycode == 's') { 
        d->player_y += 1;
        ft_printf("%d %s * %s Down pressed!\n", count, GREEN, YES);
    }
    mlx_put_image_to_window(d->mlx, d->win, t->player, d->player_x * TILE_SIZE, d->player_y * TILE_SIZE);

    return (0);
}