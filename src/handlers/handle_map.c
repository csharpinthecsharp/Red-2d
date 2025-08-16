/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:04:04 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/16 22:12:59 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
        else if (line[i] == 'P') {
            mlx_put_image_to_window(d->mlx, d->win, t->player, i * TILE_SIZE, y * TILE_SIZE);
                d->player_x = i;
                d->player_y = y;
        }
        else if (line[i] == 'C') {
            mlx_put_image_to_window(d->mlx, d->win, t->f_00, i * TILE_SIZE, y * TILE_SIZE);

            t_coin *new_coins  = realloc(d->coins, sizeof(t_coin) * (d->coin_count + 1)); 
            if (!new_coins)
            {
                    ft_printf("Memory allocation failed\n");
                    return;
            } 
            d->coins = new_coins;
            d->coins[d->coin_count].x = i;
            d->coins[d->coin_count].y = y;
            d->coin_count++;
        }
        else 
            ft_printf("%s * %s Invalid character in map: %c\n", RED, NO, line[i]);
        i++;
    }
}

void map(t_data *d, t_maps *m)
{ 
    int y; 
    int linelen = 12;
    y = 0;

    int		fd;
	char	*line;

    d->coin_count = 0;
    if (!m)
    {
        ft_printf("%s * %s MAPS: Struct failed!\n", RED, NO);
        return;
    }
    ft_printf("%s * %s MAPS: Struct successfuly loaded!\n", GREEN, YES);

    m->default_path = "./src/maps/default.ber";
    if (access(m->default_path, R_OK) != 0)
    {
        ft_printf("%s * %s MAPS: Error while loading map!\n", RED, NO);
        return;
    }
    ft_printf("%s * %s MAPS: Maps successfuly loaded!\n", GREEN, YES);


	fd = open(m->default_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Erreur lors de l'ouverture du fichier");
		return;
	}

    d->map = malloc(sizeof(char *) * linelen + 1);
    if (!d->map)
    {
        return;
    }
	while ((line = get_next_line(fd)) != NULL)
	{

        // IL FAUT QUE JE FASSE UN VRAI COUNT LINE AU 
        // LIEU DE LE HARD CODE. MAIS FLEMME Là.
        d->map[y] = ft_strdup(line); 
        print_line(line, d, &d->t, y);
        free(line);
        y++;
	}
	close(fd);
}