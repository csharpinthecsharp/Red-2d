/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:39 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 02:06:55 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_right_path(t_data *d)
{
	if (access(d->t.font_path, R_OK) != 0 || access(d->t.wall_path, R_OK) != 0
		|| access(d->t.player_path, R_OK) != 0 || access(d->t.f_00_path,
			R_OK) != 0 || access(d->t.exit_path, R_OK) != 0)
	{
		exit_error("Assets are not reachable.", d);
		return (0);
	}
	return (1);
}

void	load_t(t_data *d)
{
	init_tex(d);
	if (!is_right_path(d))
		exit_error("Error\nAssets are not reachable.", d);
	d->mlx = mlx_init();
	if (!d->mlx)
		exit_error("Error\nMLX initialization failed.", d);
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
	if (!d->t.font || !d->t.wall || !d->t.player || !d->t.f_00 || !d->t.exit)
		exit_error("Error\nTexture loading failed.", d);
}
