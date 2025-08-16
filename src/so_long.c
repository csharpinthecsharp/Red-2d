/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:43 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/16 17:52:57 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
                   
int main(void)
{
    t_data data;
    t_data *d = &data;

    t_maps maps;
    
    load_t(&data);
    openWindow(d, &d->t); 
    map(&data, &maps);
    mlx_hook(d->win, 2, 1L << 0, keyPress, d);
    set_anim_data(d); // Set the static pointer before loop starts
    mlx_loop_hook(d->mlx, animate_coin, NULL); 
    mlx_loop(d->mlx);
    return (0);
}