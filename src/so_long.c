/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:43 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 13:31:15 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    init_data(t_data *d)
{
    d->mlx = NULL;
    d->win = NULL;
    d->map = NULL;
    d->coins = NULL;
    d->t.wall = NULL;
    d->t.player = NULL;
    d->t.f_00 = NULL;
    d->t.exit = NULL;
    d->t.font = NULL;
    d->coin_count = 0;
    d->player_x = 0;
    d->player_y = 0;
    d->exit_loc_x = 0;
    d->exit_loc_y = 0;
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_maps	maps;
	t_data	*d;

	d = &data;
	if (ac == 2)
	{
		init_data(&data);
		load_t(&data);
		open_window(d, &d->t);
		map(&data, &maps, av[1]);
		mlx_hook(d->win, 2, 1L << 0, keyPress, d);
		mlx_loop(d->mlx);
	}
	else
		ft_printf("Error\nUsage: %s MAP_NAME.ber", av[0]);
	return (0);
}
