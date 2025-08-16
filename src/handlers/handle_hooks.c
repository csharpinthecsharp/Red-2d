/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:47:22 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/16 23:10:32 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


int isWall(int x, int y, t_data *d)
{
    if (d->map[y][x] == '1')
        return (1);
    return (0);
}

void is_coin(int x, int y, t_data *d)
{
    if (d->map[y][x] == 'C')
    {
        d->map[y][x] = '0';
        d->coin_count--;
        ft_printf("%s Pièce ramassée ! Il en reste %d\n", GREEN, d->coin_count);
        if (d->coin_count == 0)
            ft_printf("%s Tu as tout ramassé !\n", GREEN);
    }
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
        exit(0);
        return (0);
    }

    mlx_put_image_to_window(d->mlx, d->win, t->font, d->player_x * TILE_SIZE, d->player_y * TILE_SIZE);

    if ((keycode == 65361 || keycode == 'q') && !isWall(d->player_x - 1, d->player_y, d)) {
        is_coin(d->player_x - 1, d->player_y, d);
        d->player_x -= 1;
        ft_printf("%s%d * %s Left pressed!\n", GREEN, ++count,  YES);
    }
    else if ((keycode == 65362 || keycode == 'z') && !isWall(d->player_x, d->player_y - 1, d))  {
        is_coin(d->player_x, d->player_y - 1, d);
        d->player_y -= 1;
        ft_printf("%s%d * %s Up pressed!\n", GREEN, ++count,  YES);
    }
    else if ((keycode == 65363 || keycode == 'd') && !isWall(d->player_x + 1, d->player_y, d)) {
        is_coin(d->player_x + 1, d->player_y, d);
        d->player_x += 1;
        ft_printf("%s%d * %s Right pressed!\n", GREEN, ++count,  YES);
    }
    else if ((keycode == 65364 || keycode == 's') && !isWall(d->player_x, d->player_y + 1, d))  {
        is_coin(d->player_x, d->player_y + 1, d);
        d->player_y += 1;
        ft_printf("%s%d * %s Down pressed!\n", GREEN, ++count, YES);
    }
    mlx_put_image_to_window(d->mlx, d->win, t->player, d->player_x * TILE_SIZE, d->player_y * TILE_SIZE);

    return (0);
}