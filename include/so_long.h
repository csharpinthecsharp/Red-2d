/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:24:11 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/16 18:11:25 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 40
# define FRAME_DELAY 5000

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>


/*----- COLORS -----*/
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

/*----- EMOJI -----*/
# define NO "\xE2\x9C\x96"
# define YES "\xE2\x9C\x94"
# define CRY "\xF0\x9F\x98\xA2"

typedef struct s_textures
{
    void *font;
    char *font_path;
    void *wall;
    char *wall_path;
    void *player;
    char *player_path;

    void *f_00;
    void *f_01;
    void *f_02;
    void *f_03;
    char *f_00_path;
    char *f_01_path;
    char *f_02_path;
    char *f_03_path;

} t_textures;


typedef struct s_coin {
    int x;
    int y;
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
    t_coin coins;
    int coin_count;
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
int is_right_path(t_textures *t);

void openWindow(t_data *d, t_textures *t);
int keyPress(int keycode, t_data *d);
void map(t_data *d, t_maps *m);
int isWall(int x, int y, t_data *d);

void set_anim_data(t_data *d);
int animate_coin(void);

void print_line(char *line, t_data *d, t_textures *t, int y);
void free_textures(t_data *d, t_textures *t);

#endif