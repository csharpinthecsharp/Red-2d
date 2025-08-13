/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:43 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/12 16:05:18 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(void)
{
    t_data data;
    t_data *d = &data;

    t_maps maps;
    t_maps *m = &maps;

    load_t(&data);
    openWindow(d, &d->t); 


    if (!m)
    {
        ft_printf("%s * %s MAPS: Struct failed!\n", RED, NO);
        return (0);
    }
    ft_printf("%s * %s MAPS: Struct successfuly loaded!\n", GREEN, YES);

    m->default_path = "./src/maps/default.ber";
    if (access(m->default_path, R_OK) != 0)
    {
        ft_printf("%s * %s MAPS: Error while loading map!\n", RED, NO);
        return (0);
    }
    ft_printf("%s * %s MAPS: Maps successfuly loaded!\n", GREEN, YES);

    mlx_hook(d->win, 2, 1L << 0, exitKey, d);
    mlx_loop(d->mlx);
    return (0);
}

