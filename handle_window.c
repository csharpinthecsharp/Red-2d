/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:37 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 02:06:48 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_data *d)
{
	d->win = mlx_new_window(d->mlx, 1400, 500, "so_long");
	if (!d->win)
		exit_error("Window failed to create", d);
}
