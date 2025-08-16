/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:33:09 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/16 18:09:29 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

static t_data *anim_data = NULL;

void set_anim_data(t_data *d)
{
    anim_data = d;
}

int animate_coin(void)
{
    static int frame = 0;
    static int tick = 0;

    if (!anim_data)
        return (0);

    t_textures *t = &anim_data->t;
    int x = anim_data->coins.x;
    int y = anim_data->coins.y;

    void *frames[] = { t->f_00, t->f_01, t->f_02, t->f_03 };
    mlx_put_image_to_window(anim_data->mlx, anim_data->win, frames[frame], x * TILE_SIZE, y * TILE_SIZE);

    tick++;
    if (tick >= FRAME_DELAY)
    {
        frame = (frame + 1) % 4;
        tick = 0;
    }

    return (0);
}
