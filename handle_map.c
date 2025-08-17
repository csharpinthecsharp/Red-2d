/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 03:04:04 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/18 00:15:47 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_basic_tile(t_data *d, int i, char tile, int y)
{
    if (tile == '0')
        mlx_put_image_to_window(d->mlx, d->win, d->t.font, i * TILE_SIZE, y * TILE_SIZE);
    else if (tile == '1')
        mlx_put_image_to_window(d->mlx, d->win, d->t.wall, i * TILE_SIZE, y * TILE_SIZE);
    else if (tile == 'P')
    {
        mlx_put_image_to_window(d->mlx, d->win, d->t.player, i * TILE_SIZE, y * TILE_SIZE);
        d->player_x = i;
        d->player_y = y;
    }
    else if (tile == 'E')
    {
        mlx_put_image_to_window(d->mlx, d->win, d->t.font, i * TILE_SIZE, y * TILE_SIZE);
        d->exit_loc_x = i;
        d->exit_loc_y = y;
    }
}

void handle_coin(t_data *d, int i, int y)
{
    t_coin *new_coins;
    
    mlx_put_image_to_window(d->mlx, d->win, d->t.f_00, i * TILE_SIZE, y * TILE_SIZE);
    new_coins = realloc(d->coins, sizeof(t_coin) * (d->coin_count + 1));
    if (!new_coins)
    {
        ft_printf("Error\nRealloc failed.\n");
        return ;
    }
    d->coins = new_coins;
    d->coins[d->coin_count].x = i;
    d->coins[d->coin_count].y = y;
    d->coin_count++;
}

void print_line(t_data *d, char *line, int y)
{
    int i;
    
    if (!d->t.font || !d->t.wall || !d->t.player || !d->t.f_00)
    {
        ft_printf("Error\nTexture failed to load into the map.\n");
        return ;
    }
    i = 0;
    while (line[i])
    {
        if (line[i] == 'C')
            handle_coin(d, i, y);
        else
            draw_basic_tile(d, i, line[i], y);
        i++;
    }
}

void map(t_data *d, char *ber)
{
    int fd;
    int y;
    char *line;
    
    d->map_path = ber;
    if (!ber || access(d->map_path, R_OK) != 0)
        exit_error("Map failed to load.", d);
    if ((fd = open(d->map_path, O_RDONLY)) < 0)
        exit_error("Map failed to be read.", d);
    if (!rules_check(d))
        exit_error("Textures rules are missing.", d);
    if (!is_rectangular(d))
        exit_error("Map is not rectangular.", d);
    if (!(d->map = malloc(sizeof(char *) * (line_count(d) + 1))))
        exit_error("Map allocation failed.", d);
    y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        d->map[y] = ft_strdup(line);
        print_line(d, line, y);
        y++;
        free(line);
    }
    d->map[y] = NULL;
    close(fd);
}