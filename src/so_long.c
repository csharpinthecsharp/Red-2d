/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:25:43 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/12 16:05:18 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(void)
{
    t_data data;
    t_data *d = &data;

    t_maps maps;
    t_maps *m = &maps;

    int		fd;
	char	*line;

    load_t(&data);
    openWindow(d, &d->t); 

    if (!m)
    {
        ft_printf("%s * %s MAPS: Struct failed!\n", RED, NO);
        return (0);
    }
    ft_printf("%s * %s MAPS: Struct successfuly loaded!\n", GREEN, YES);

    m->default_path = "./src/maps/default.ber";
    if (access(m->default_path, R_OK) != 0)
    {
        ft_printf("%s * %s MAPS: Error while loading map!\n", RED, NO);
        return (0);
    }
    ft_printf("%s * %s MAPS: Maps successfuly loaded!\n", GREEN, YES);

	fd = open("./src/maps/default.ber", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s", line);
		free(line);
	}
	close(fd);

    mlx_hook(d->win, 2, 1L << 0, exitKey, d);
    mlx_loop(d->mlx);
    return (0);
}