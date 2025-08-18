/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:30:40 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 18:30:58 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int is_unique_text(t_data *d)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (d->map[i] != NULL)
    {
        j = 0;
        while (d->map[i][j] != '\0')
        {
            if (d->map[i][j] == 'P' || d->map[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    if (count > 2)
        return (0);
    return (1);
}