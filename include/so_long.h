/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:24:11 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 01:52:25 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 40

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_textures
{
    void *font;
    char *font_path;

    void *wall;
    char *wall_path;

    void *player;
    char *player_path;

    void *f_00;
    char *f_00_path;
    
    void *exit;
    char *exit_path;
} t_textures;


typedef struct s_coin {
    int x;
    int y;
    int status;
}   t_coin;

typedef struct s_data
{
    void *mlx;
    void *win;    
    int width;
    int height;
    int player_x;
    int player_y;
    t_textures t;  
    char **map;
    t_coin *coins;
    int coin_count;
    int exit_loc_x;
    int exit_loc_y;
} t_data;

typedef struct s_maps
{
    void *defa;
    char *default_path;
} t_maps;

/*
** NAME: Handlers
** PATH: /so_long/handlers/
** DESC: Handlers function are meant to handle some cases.
*/
void load_t(t_data *d);
void load_t_path(t_textures *t);
int is_right_path(t_textures *t, t_data *d);

void openWindow(t_data *d, t_textures *t);
int keyPress(int keycode, t_data *d);
int isWall(int x, int y, t_data *d);
void is_coin(int x, int y, t_data *d);
int close_game(t_data *d);
void map(t_data *d, t_maps *m, char *ber);

void print_line(char *line, t_data *d, t_textures *t, int y);
void free_textures(t_data *d, t_textures *t);

#endif