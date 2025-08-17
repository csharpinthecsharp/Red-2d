/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:39 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 14:06:12 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_right_path(t_textures *t, t_data *d)
{
	int		i;
	char	*paths[5];

	if (!t)
	{
		ft_printf("Error\nTexture failed.\n");
		close_game(d);
	}
	paths[0] = t->font_path;
	paths[1] = t->wall_path;
	paths[2] = t->player_path;
	paths[3] = t->f_00_path;
	paths[4] = t->exit_path;
	i = 0;
	while (i <= 4)
	{
		if (access(paths[i], R_OK) != 0)
		{
			ft_printf("Error\nAssets are not reachable.\n");
			return (0);
		}
		i += 1;
	}
	return (1);
}

void	load_t_path(t_textures *t)
{
	t->font_path = "./src/textures/font.xpm";
	t->wall_path = "./src/textures/wall.xpm";
	t->player_path = "./src/textures/player.xpm";
	t->f_00_path = "./src/textures/animation/f_00.xpm";
	t->exit_path = "./src/textures/exit.xpm";
}

void	load_t(t_data *d)
{
    load_t_path(&d->t);
    if (!is_right_path(&d->t, d))
    {
        ft_printf("Error\nTexture paths are invalid.\n");
        close_game(d);
    }
    d->mlx = mlx_init();
    if (!d->mlx)
    {
        ft_printf("Error\nMlx is not set.\n");
        exit(EXIT_FAILURE);
    }
}
