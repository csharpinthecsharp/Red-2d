/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:45:56 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 15:03:30 by ltrillar         ###   ########.fr       */
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

int	line_count(t_data *d)
{
	int		fd, count;
	char	*line;

	count = 0;
	fd = open(d->map_path, O_RDONLY);
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

int	fline_count(t_data *d)
{
	int		y;
    
	y = 0;
	while (d->map[y])
		y++;
	return (y);
}

int is_rectangular(t_data *d)
{
	int x = 0, first_len, current_len;
	
	first_len = ft_strlen(d->map[0]);
	while (d->map[x])
	{
		current_len = ft_strlen(d->map[x]);
		if (current_len != first_len)
			return (0);
		x++;
	}
	return (1);
}

int is_enclosed_by_walls(t_data *d)
{
	int x = 0, y, height, width;
	
	if (!d->map || !(d->map[0]))
		return (0);
	
	height = line_count(d);
	width = ft_strlen(d->map[0]);
	y = 0;
	while (y < width)
	{
		if (d->map[0][y] != '1' || (d->map[height - 1][y] != '1'))
			return (0);
		y++;
	}
	x = 0;
	while (x < height)
	{
		if (d->map[x][0] != '1' || (d->map[x][width - 1] != '1'))
			return (0);
		x++;
	}
	
	return (1);
}

int is_valid_map(t_data *d)
{
	return (is_rectangular(d) &&
     rules_check(d)) &&
    is_enclosed_by_walls(d);
}