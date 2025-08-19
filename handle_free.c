/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:01:10 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 02:10:20 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_data *d)
{
	if (!d->mlx)
		return ;
	if (d->t.font)
		mlx_destroy_image(d->mlx, d->t.font);
	if (d->t.wall)
		mlx_destroy_image(d->mlx, d->t.wall);
	if (d->t.player)
		mlx_destroy_image(d->mlx, d->t.player);
	if (d->t.f_00)
		mlx_destroy_image(d->mlx, d->t.f_00);
	if (d->t.exit)
		mlx_destroy_image(d->mlx, d->t.exit);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	map[i] = NULL;
}

void	free_coins(t_data *d)
{
	if (d->coins)
		free(d->coins);
}

int	close_game(t_data *d, int status)
{
	if (d)
	{
		if (d->win && d->mlx)
			mlx_destroy_window(d->mlx, d->win);
		free_textures(d);
		free_map(d->map);
		free_coins(d);
		if (d->mlx)
		{
			mlx_destroy_display(d->mlx);
			free(d->mlx);
		}
	}
	exit(status);
}
