/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:07:02 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/12 16:17:02 by ltrillar         ###   ########.fr       */
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