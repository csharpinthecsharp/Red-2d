/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:45:56 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 18:31:22 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int format_check(char *str)
{
    int len;

    len = ft_strlen(str);
    if (len < 4)
        return (0);
    if (ft_strncmp(str + len - 4, ".ber", 4) == 0)
        return (1);
    return (0);
}
int rules_check(t_data *d)
{
    int x, y, elements;
    elements = 0, x = 0, y = 0;
	char c;

	while (d->map[x] != NULL)
	{
		y = 0;
		while (d->map[x][y] != '\0')
		{
			c = d->map[x][y];
			if (c == '1' && !(elements & 1))
				elements |= 1;
			else if (c == '0' && !(elements & 2))
				elements |= 2;
			else if (c == 'E' && !(elements & 4))
				elements |= 4;
			else if (c == 'C' && !(elements & 8))
				elements |= 8;
			else if (c == 'P' && !(elements & 16))
				elements |= 16;
			y++;
		}
		x++;
	}
	return ((elements & 31) == 31);
}

int is_valid_map(t_data *d)
{
	return (is_rectangular(d) &&
     rules_check(d)) &&
    is_enclosed_by_walls(d) &&
	is_unique_text(d);
}
