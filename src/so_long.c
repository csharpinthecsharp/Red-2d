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

void print_line(char *line, t_data *d, t_textures *t, int y)
{
    int i = 0;

    if (!t->font || !t->wall) {
        ft_printf("%s * %s Error: textures not loaded properly!\n", RED, NO);
        return;
    }

    while (line[i])
    {
        if (line[i] == '0') {
            mlx_put_image_to_window(d->mlx, d->win, t->font, i * TILE_SIZE, y * TILE_SIZE);
        }
        else if (line[i] == '1') {
            mlx_put_image_to_window(d->mlx, d->win, t->wall, i * TILE_SIZE, y * TILE_SIZE);
        }
        else 
            ft_printf("%s * %s Invalid character in map: %c\n", RED, NO, line[i]);
        i++;
    }
}

void free_textures(t_data *d, t_textures *t)
{
    if (t->font_path)
        mlx_destroy_image(d->mlx, t->font);
    if (t->wall_path)
        mlx_destroy_image(d->mlx, t->wall);
}
                        
int main(void)
{
    t_data data;
    t_data *d = &data;

    t_maps maps;
    t_maps *m = &maps;

    int y; 
    y = 0;

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
        print_line(line, d, &d->t, y);
        free(line);
        y++;
	}
	close(fd);
    free_textures(d, &d->t);
    ft_printf("%s * %s FREE: Textures successfuly freed!\n", GREEN, YES);

    mlx_hook(d->win, 2, 1L << 0, exitKey, d);
    mlx_loop(d->mlx);
    return (0);
}