/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:39 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 00:15:45 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_right_path(t_data *d)
{
	int		i;
	char	*paths[5];

	paths[0] = d->t.font_path;
	paths[1] = d->t.wall_path;
	paths[2] = d->t.player_path;
	paths[3] = d->t.f_00_path;
	paths[4] = d->t.exit_path;
	i = 0;
	while (i <= 4)
	{
		if (access(paths[i], R_OK) != 0)
		{
			exit_error("Assets are not reachable.", d);
			return (0);
		}
		i += 1;
	}
	return (1);
}

void	load_t(t_data *d)
{
	init_tex(d);
    if (!is_right_path(d))
        close_game(d);
    d->mlx = mlx_init();
    if (!d->mlx)
    {
        ft_printf("Error\nMlx is not set.\n");
        exit(EXIT_FAILURE);
    }
}
