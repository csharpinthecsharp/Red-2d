/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:04:04 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 20:40:36 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_basic_tile(int i, char tile, t_render_args *a)
{
	if (tile == '0')
		mlx_put_image_to_window(a->d->mlx, a->d->win, a->t->font, i * TILE_SIZE,
			a->y * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(a->d->mlx, a->d->win, a->t->wall, i * TILE_SIZE,
			a->y * TILE_SIZE);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(a->d->mlx, a->d->win, a->t->player, i
			* TILE_SIZE, a->y * TILE_SIZE);
		a->d->player_x = i;
		a->d->player_y = a->y;
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(a->d->mlx, a->d->win, a->t->font, i * TILE_SIZE,
			a->y * TILE_SIZE);
		a->d->exit_loc_x = i;
		a->d->exit_loc_y = a->y;
	}
}

void	handle_coin(int i, t_render_args *a)
{
	t_coin	*new_coins;

	mlx_put_image_to_window(a->d->mlx, a->d->win, a->t->f_00, i * TILE_SIZE, a->y
		* TILE_SIZE);
	new_coins = realloc(a->d->coins, sizeof(t_coin) * (a->d->coin_count + 1));
	if (!new_coins)
	{
		ft_printf("Error\nRealloc failed.\n");
		return ;
	}
	a->d->coins = new_coins;
	a->d->coins[a->d->coin_count].x = i;
	a->d->coins[a->d->coin_count].y = a->y;
	a->d->coin_count++;
}

void	print_line(char *line, t_render_args *a)
{
	int	i;

	if (!a->t->font || !a->t->wall || !a->t->player || !a->t->f_00)	{
		ft_printf("Error\nTexture failed to load into the map.\n");
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			handle_coin(i, a);
		else
			draw_basic_tile(i, line[i], a);
		i++;
	}
}

int	line_count(t_data *d, t_maps *m)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(m->default_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap failed to be read.\n");
		close_game(d);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	map(t_data *d, t_maps *m, char *ber)
{
	int				fd;
	int				y;
	char			*line;
	t_render_args	args;

	if (!m || access((m->default_path = ber), R_OK) != 0)
		exit_error("Map failed to load.", d);
	if ((fd = open(m->default_path, O_RDONLY)) < 0)
		exit_error("Map failed to be read.", d);
	if (!(d->map = malloc(sizeof(char *) * (line_count(d, m) + 1))))
		exit_error("Map allocation failed.", d);
	y = 0;
	args.d = d;
	args.t = &d->t;
	while ((line = get_next_line(fd)) != NULL)
	{
		d->map[y] = ft_strdup(line);
		args.y = y++;
		print_line(line, &args);
		free(line);
	}
	d->map[y] = NULL;
	close(fd);
	//if (!textures_check(d))
	//	exit_error("Texture failed to load into the map.", d);
}