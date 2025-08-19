/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:04:04 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 02:06:58 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_basic_tile(t_data *d, int i, char tile, int y)
{
	if (tile == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->t.font, i * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->t.wall, i * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->t.player, i * TILE_SIZE, y
			* TILE_SIZE);
		d->player_x = i;
		d->player_y = y;
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->t.font, i * TILE_SIZE, y
			* TILE_SIZE);
		d->exit_loc_x = i;
		d->exit_loc_y = y;
	}
}

void	handle_coin(t_data *d, int i, int y)
{
	t_coin	*new_coins;
	int		j;

	mlx_put_image_to_window(d->mlx, d->win, d->t.f_00, i * TILE_SIZE, y
		* TILE_SIZE);
	new_coins = ft_calloc(d->coin_count + 1, sizeof(t_coin));
	if (!new_coins)
	{
		exit_error("Allocation failed", d);
		return ;
	}
	j = 0;
	while (j < d->coin_count)
	{
		new_coins[j] = d->coins[j];
		j++;
	}
	free(d->coins);
	d->coins = new_coins;
	d->coins[d->coin_count].x = i;
	d->coins[d->coin_count].y = y;
	d->coin_count++;
}

void	print_line(t_data *d, char *line, int y)
{
	int	i;

	if (!d->t.font || !d->t.wall || !d->t.player || !d->t.f_00)
	{
		ft_printf("Error\nTexture failed to load into the map.\n");
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			handle_coin(d, i, y);
		else
			draw_basic_tile(d, i, line[i], y);
		i++;
	}
}

void	load_map_lines(t_data *d, int fd)
{
	int		y;
	char	*line;
	char	*wash;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		wash = ft_strtrim(line, "\n");
		d->map[y] = ft_strdup(wash);
		print_line(d, wash, y);
		y++;
		free(wash);
		free(line);
		line = get_next_line(fd);
	}
	d->map[y] = NULL;
	if (y == 0)
		exit_error("Map is empty.", d);
}

void	map(t_data *d, char *ber)
{
	int	fd;

	d->map_path = ber;
	if (!ber || access(d->map_path, R_OK) != 0)
		exit_error("Map failed to load.", d);
	fd = open(d->map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Map failed to be read.", d);
	d->map = malloc(sizeof(char *) * (line_count(d) + 1));
	if (!d->map)
		exit_error("Map allocation failed.", d);
	load_map_lines(d, fd);
	close(fd);
	if (!is_valid_map(d))
		exit_error("Map is not valid.", d);
}
