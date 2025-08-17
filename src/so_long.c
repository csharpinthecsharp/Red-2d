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

int	main(int ac, char *av[])
{
	t_data	data;
	t_maps	maps;
	t_data	*d;

	d = &data;
	if (ac == 2)
	{
		data.coins = NULL;
		d->coin_count = 0;
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
