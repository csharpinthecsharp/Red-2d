/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:45:56 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 00:15:51 by ltrillar         ###   ########.fr       */
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
    int fd, i, elements = 0;
    char *line;

    fd = open(d->map_path, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        i = 0;
        while (line[i] && line[i] != '\n')
        {
            if (line[i] == '1' && !(elements & 1))
                elements |= 1;
            else if (line[i] == '0' && !(elements & 2))
                elements |= 2;
            else if (line[i] == 'E' && !(elements & 4))
                elements |= 4;
            else if (line[i] == 'C' && !(elements & 8))
                elements |= 8;
            else if (line[i] == 'P' && !(elements & 16))
                elements |= 16;
            i++;
        }
        free(line);
    }
    close(fd);
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

int fline_count(t_data *d)
{
    int fd, count;
    char *line;
    
    fd = open((d)->map_path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nMap failed to be read.\n");
        close_game(d);
    }
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (0);
    }
    count = ft_strlen(line);
    if (line[count - 1] == '\n')
        count--;
    free(line);
    close(fd);
    return (count);
}

int is_rectangular(t_data *d)
{
    if (line_count(d) < fline_count(d))
        return (1);
    return (0);
}