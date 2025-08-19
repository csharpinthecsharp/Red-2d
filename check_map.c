/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:45:56 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 01:45:35 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	format_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (ft_strncmp(str + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	rules_check_element(char c, t_data *d)
{
	if (c == '1')
		d->flags.wall = 1;
	else if (c == '0')
		d->flags.empty = 1;
	else if (c == 'E')
		d->flags.exit = 1;
	else if (c == 'C')
		d->flags.coll = 1;
	else if (c == 'P')
		d->flags.player = 1;
}

int	rules_check(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (d->map[x])
	{
		y = 0;
		while (d->map[x][y])
		{
			rules_check_element(d->map[x][y], d);
			y++;
		}
		x++;
	}
	if (d->flags.wall && d->flags.empty && d->flags.exit && d->flags.coll
		&& d->flags.player)
		return (1);
	return (0);
}

int	is_valid_map(t_data *d)
{
	return ((is_rectangular(d) && rules_check(d)) && is_enclosed_by_walls(d)
		&& is_unique_text(d));
}
