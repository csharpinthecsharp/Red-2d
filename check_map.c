/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:45:56 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 21:29:18 by ltrillar         ###   ########.fr       */
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

int	rules_check(t_data *d)
{
	int	x;
	int	y;
	int	e;

	x = 0;
	e = 0;
	while (d->map[x])
	{
		y = 0;
		while (d->map[x][y])
		{
			e = rules_check_element(d->map[x][y], e);
			y++;
		}
		x++;
	}
	return ((e & 31) == 31);
}

int	rules_check_element(char c, int e)
{
	if (c == '1' && !(e & 1))
		e |= 1;
	else if (c == '0' && !(e & 2))
		e |= 2;
	else if (c == 'E' && !(e & 4))
		e |= 4;
	else if (c == 'C' && !(e & 8))
		e |= 8;
	else if (c == 'P' && !(e & 16))
		e |= 16;
	return (e);
}

int	is_valid_map(t_data *d)
{
	return ((is_rectangular(d) && rules_check(d)) && is_enclosed_by_walls(d)
		&& is_unique_text(d));
}
