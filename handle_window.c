/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:37 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 15:56:45 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_data *d)
{
	d->t.font = mlx_xpm_file_to_image(d->mlx, d->t.font_path, &d->width,
			&d->height);
	d->t.wall = mlx_xpm_file_to_image(d->mlx, d->t.wall_path, &d->width,
			&d->height);
	d->t.player = mlx_xpm_file_to_image(d->mlx, d->t.player_path, &d->width,
			&d->height);
	d->t.f_00 = mlx_xpm_file_to_image(d->mlx, d->t.f_00_path, &d->width,
			&d->height);
	d->t.exit = mlx_xpm_file_to_image(d->mlx, d->t.exit_path, &d->width,
			&d->height);
	if (!d->t.font || !d->t.wall)
		exit_error("Error\nTexture failed", d);
	d->win = mlx_new_window(d->mlx, 1400, 500, "so_long");
	if (!d->win)
		exit_error("Window failed to create", d);
}
