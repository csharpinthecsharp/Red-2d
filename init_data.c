/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:21:31 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 02:12:03 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_data *d)
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
	d->map_path = NULL;
	d->coin_count = 0;
	d->player_x = 0;
	d->player_y = 0;
	d->count = 0;
	d->exit_loc_x = 0;
	d->exit_loc_y = 0;
	d->width = 0;
	d->height = 0;
	d->flags.wall = 0;
	d->flags.empty = 0;
	d->flags.exit = 0;
	d->flags.coll = 0;
	d->flags.player = 0;
}

void	init_tex(t_data *d)
{
	d->t.font_path = "./textures/font.xpm";
	d->t.wall_path = "./textures/wall.xpm";
	d->t.player_path = "./textures/player.xpm";
	d->t.f_00_path = "./textures/f_00.xpm";
	d->t.exit_path = "./textures/exit.xpm";
}
