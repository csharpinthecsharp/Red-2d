/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:47:22 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 23:24:41 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_wall(int x, int y, t_data *d)
{
	if (d->map[y][x] == '1')
		return (1);
	return (0);
}

void	is_coin(int x, int y, t_data *d)
{
	if (d->map[y][x] == 'C')
	{
		d->map[y][x] = '0';
		d->coin_count--;
		if (d->coin_count == 0)
		{
			if (!d->t.exit || d->exit_loc_x == -1 || d->exit_loc_y == -1)
			{
				ft_printf("Error\nThe exit is not set.\n");
				close_game(d);
			}
			mlx_put_image_to_window(d->mlx, d->win, d->t.exit, d->exit_loc_x
				* TILE_SIZE, d->exit_loc_y * TILE_SIZE);
		}
	}
	if ((d->map[y][x] == 'E') && (d->coin_count == 0))
	{
		ft_printf("Success, you found the exit!\n");
		close_game(d);
	}
}
int keyPress(int keycode, t_data *d)
{	
    int new_x = (d)->player_x, new_y = (d)->player_y;
    if (keycode == 65307)
        close_game(d);
    mlx_put_image_to_window(d->mlx, d->win, d->t.font, d->player_x * TILE_SIZE, d->player_y * TILE_SIZE);
    if ((keycode == 65361 || keycode == 'q') && !is_wall(d->player_x - 1, d->player_y, d))
        new_x = d->player_x - 1;
    else if ((keycode == 5362 || keycode == 'z') && !is_wall(d->player_x, d->player_y - 1, d))
        new_y = d->player_y - 1;
    else if ((keycode == 65363 || keycode == 'd') && !is_wall(d->player_x + 1, d->player_y, d))
        new_x = d->player_x + 1;
    else if ((keycode == 65364 || keycode == 's') && !is_wall(d->player_x, d->player_y + 1, d))
        new_y = d->player_y + 1;
    if (new_x != d->player_x || new_y != d->player_y)
    {
        is_coin(new_x, new_y, d);
        d->player_x = new_x;
        d->player_y = new_y;
        ft_printf("%d\n", ++d->count);
    }
    mlx_put_image_to_window(d->mlx, d->win, d->t.player, d->player_x * TILE_SIZE, d->player_y * TILE_SIZE);
    return (0);
}